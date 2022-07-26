/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */

#include "EvalExpression.h"
#include "Server.h"
#include "Renderer.h"
#include "Role.h"
#include "Page.h"
#include "StringStream.h"

//---- EvalExpression ---------------------------------------------------------------
RegisterAction(EvalExpression);

EvalExpression::EvalExpression(const char *name) : Action(name) { }

EvalExpression::~EvalExpression() { }

bool EvalExpression::DoExecAction(String &transitionToken, Context &ctx, const ROAnything &config)
{
	// this is the new method that also gets a config ( similar to Renderer::RenderAll )
	// write the action code here - you don't have to override DoAction anymore
	StartTrace(EvalExpression.DoExecAction);

	TraceAny(config, "config: ");
	String srcSlot("fields.src");
	ROAnything srcLoc;
	if (config.LookupPath(srcLoc, "RendererSlot"))
	{
		srcSlot="";
		Renderer::RenderOnString(srcSlot, ctx, srcLoc);
	}
	Trace("srcSlot<" << srcSlot << ">");
	// read in the renderer
	Anything renderer;
	String strIn(ctx.Lookup(srcSlot,""));
	IStringStream isConfig(strIn);
	renderer.Import(isConfig, srcSlot);
	TraceAny(renderer, "Renderer Config");

	// produce result
	Context renderCtx(ctx.GetEnvStore(), ctx.GetQuery(), Server::FindServer("Server"), ctx.GetSession(), Role::FindRole(ctx.Lookup("fields.Role", "Role")), Page::FindPage(ctx.Lookup("fields.Page", "Page")));

	// read in the tmpStore
	srcSlot= "fields.tmpStore";
	if (config.LookupPath(srcLoc, "StateSlot"))
	{
		srcSlot="";
		Renderer::RenderOnString(srcSlot, ctx, srcLoc);
	}
	strIn = ctx.Lookup(srcSlot,"");
	IStringStream isEnv(strIn);
	renderCtx.GetTmpStore().Import(isEnv, srcSlot);
	TraceAny(renderCtx.GetTmpStore(), "tmpStore");

	// copy to real tmpStore
	Anything tmp2= renderCtx.GetTmpStore();
	for (long i= 0; i<tmp2.GetSize(); i++)
		ctx.GetTmpStore()[tmp2.SlotName(i)]= tmp2[i];

	String result("<");
	String result1;
	Renderer::RenderOnString(result1, renderCtx, renderer);
	result << result1 << ">";
	Trace("result:" << result);

	// store it as source code
	ctx.GetTmpStore()["Result"]= result;

	// store it for rendering
	ctx.GetTmpStore()["Result1"]= result1;

	transitionToken= "GoRenderTest";
	return true;

}
