/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */

#include "EvalAction.h"
#include "Server.h"
#include "Renderer.h"
#include "Role.h"
#include "Page.h"
#include "StringStream.h"

//---- EvalAction ---------------------------------------------------------------
RegisterAction(EvalAction);

EvalAction::EvalAction(const char *name) : Action(name) { }

EvalAction::~EvalAction() { }

bool EvalAction::DoExecAction(String &transitionToken, Context &ctx, const ROAnything &config)
{
	// this is the new method that also gets a config ( similar to Renderer::RenderAll )
	// write the action code here - you don't have to override DoAction anymore
	StartTrace(EvalAction.DoExecAction);

	TraceAny(config, "config: ");
	String srcSlot("fields.src");
	ROAnything srcLoc;
	if (config.LookupPath(srcLoc, "ActionSlot"))
	{
		srcSlot="";
		Renderer::RenderOnString(srcSlot, ctx, srcLoc);
	}
	Trace("srcSlot<" << srcSlot << ">");
	// read in the action
	Anything action;
	String strIn(ctx.Lookup(srcSlot,""));
	IStringStream isConfig(strIn);
	action.Import(isConfig, srcSlot);
	TraceAny(action, "Action Config");

	// read in the actionToken
	String actiontransitionToken(ctx.GetQuery()["fields"]["ActionToken"].AsString());
	Trace("actiontransitionToken<" << actiontransitionToken << ">");

	// setup the specific context
	Context actionCtx(ctx.GetEnvStore(), ctx.GetQuery(), Server::FindServer("Server"), ctx.GetSession(), Role::FindRole(ctx.Lookup("fields.Role", "Role")), Page::FindPage(ctx.Lookup("fields.Page", "Page")));

	// read in the tmpStore
	srcSlot= "fields.tmpStore";
	if (config.LookupPath(srcLoc, "StateSlot"))
	{
		srcSlot="";
		Renderer::RenderOnString(srcSlot, ctx, srcLoc);
	}
	strIn = ctx.Lookup(srcSlot,"");
	IStringStream isEnv(strIn);
	actionCtx.GetTmpStore().Import(isEnv, srcSlot);
	TraceAny(actionCtx.GetTmpStore(), "tmpStore");

	// copy to real tmpStore
	Anything tmp2= actionCtx.GetTmpStore();
	for (long i= 0; i<tmp2.GetSize(); i++)
		ctx.GetTmpStore()[tmp2.SlotName(i)]= tmp2[i];

	// put action to actionCtx
	actionCtx.GetQuery()["action"] = actiontransitionToken;

	String requestb, tmpb, sessionb;
	OStringStream orequest(&requestb), otmp(&tmpb), osession(&sessionb);
	// actionCtx before:
	actionCtx.GetRequest().Export(orequest,false);
	actionCtx.GetTmpStore().Export(otmp,false);
	actionCtx.GetSessionStore().Export(osession,false);
	ctx.GetTmpStore()["Requestb"]= requestb;
	ctx.GetTmpStore()["Tmpb"]= tmpb;
	ctx.GetTmpStore()["Sessionb"]= sessionb;

	if (Action::ExecAction(actiontransitionToken, actionCtx, action)) {
		ctx.GetTmpStore()["Actionreturn"]="Action has ended succesfully";
	} else {
		ctx.GetTmpStore()["Actionreturn"]="Action failed";
	}

	String requesta, tmpa, sessiona;
	OStringStream orequesta(&requesta), otmpa(&tmpa), osessiona(&sessiona);
	// actionCtx after:
	actionCtx.GetRequest().Export(orequesta,false);
	actionCtx.GetTmpStore().Export(otmpa,false);
	actionCtx.GetSessionStore().Export(osessiona,false);
	ctx.GetTmpStore()["Requesta"]= requesta;
	ctx.GetTmpStore()["Tmpa"]= tmpa;
	ctx.GetTmpStore()["Sessiona"]= sessiona;
	if (requesta == requestb) {
		ctx.GetTmpStore()["RequestDiffer"]="NO";
	} else {
		ctx.GetTmpStore()["RequestDiffer"]="YES";
	}
	if (tmpa == tmpb) {
		ctx.GetTmpStore()["TmpDiffer"]="NO";
	} else {
		ctx.GetTmpStore()["TmpDiffer"]="YES";
	}
	if (sessiona == sessionb) {
		ctx.GetTmpStore()["SessionDiffer"]="NO";
	} else {
		ctx.GetTmpStore()["SessionDiffer"]="YES";
	}

	transitionToken= "GoActionTest";
	return true;
}
