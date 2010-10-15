/*
 * Copyright (c) 1999 itopia
 * All Rights Reserved
 *
 * $Id$
 */

#ifdef __GNUG__
#pragma implementation
#endif

//--- interface ------------
#include "ReadWriteAction.h"

#include "Dbg.h"
#include "System.h"
#include "Renderer.h"
#include "AnythingUtils.h"

//---- ReadAction ---------------------------------------------------------------

RegisterAction(ReadAction);

ReadAction::ReadAction(const char *name) : Action(name) { }

ReadAction::~ReadAction() { }

bool ReadAction::DoExecAction(String &transitionToken, Context &ctx, const ROAnything &config)
{
	// this is the new method that also gets a config ( similar to Renderer::RenderAll )
	// write the action code here - you don't have to override DoAction anymore
	StartTrace(ReadAction.DoExecAction);

	ROAnything filename;
	ROAnything slotname;
	Anything containercopy;

	if (! (config.LookupPath(filename,"Filename") && config.LookupPath(slotname,"Slotname") )) {
		return false;
	}

	TraceAny(filename,"Filename");
	TraceAny(slotname,"Slotname");

	std::iostream *ifp= System::OpenIStream( filename.AsString(), "any" );
	if (ifp) {
		containercopy.Import (*ifp);
		delete ifp;
		Trace("reading ok");
	} else {
		Trace("reading nok");
		return false;
	}
	Trace("reading ok");
	TraceAny(containercopy,"ContainerCopy");

	StorePutter::Operate(containercopy, ctx, "Session", slotname.AsString());
	return true;
}

//---- WriteAction ---------------------------------------------------------------

RegisterAction(WriteAction);

WriteAction::WriteAction(const char *name) : Action(name) { }

WriteAction::~WriteAction() { }

bool WriteAction::DoExecAction(String &transitionToken, Context &ctx, const ROAnything &config)
{
	// this is the new method that also gets a config ( similar to Renderer::RenderAll )
	// write the action code here - you don't have to override DoAction anymore
	StartTrace(WriteAction.DoExecAction);

	ROAnything filename;
	String containerKey;

	Renderer::RenderOnString(containerKey, ctx, config["Container"]);
	Anything containercopy;

	if (! (config.LookupPath(filename,"Filename") && (containerKey.Length() > 0)) )
	{
		TraceAny(filename,"Filename");
		Trace("ContainerKey:<" << containerKey << ">");
		return false;
	}

	TraceAny(filename,"Filename");
	Trace("ContainerKey:<" << containerKey << ">");

	containercopy= ctx.Lookup(containerKey).DeepClone();
	TraceAny(containercopy,"Container");

	std::iostream *ofp= System::OpenOStream( filename.AsString(), "any" );
	if (ofp) {
		containercopy.Export (*ofp);
		delete ofp;
		Trace("writing ok");
	} else {
		Trace("writing nok");
		return false;
	}

	return true;
}
