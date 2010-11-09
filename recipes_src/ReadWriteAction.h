/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */

#ifndef _ReadWriteAction_H
#define _ReadWriteAction_H

//---- Action include -------------------------------------------------
#include "Action.h"
#include "config_recipes.h"

//---- ReadAction ----------------------------------------------------------
//! comment action
//!	Structure of config:
//!<PRE>	{
//!		/Slot1	....
//!      ...
//!	}</PRE>
class EXPORTDECL_RECIPES ReadAction : public Action
{
public:
	//--- constructors
    ReadAction(const char *name);
    ~ReadAction();

    //!DoSomething method for configured Actions
	//! \param transitionToken (in/out) the event passed by the caller, can be modified.
	//! \param ctx the context the action runs within.
	//! \param config the configuration of the action.
	//! \return true if the action run successfully, false if an error occurred.
	virtual bool DoExecAction(String &transitionToken, Context& ctx, const ROAnything &config);

};

//---- WriteAction ----------------------------------------------------------
//! comment action
//!	Structure of config:
//!<PRE>	{
//!		/Slot1	....
//!      ...
//!	}</PRE>
class EXPORTDECL_RECIPES WriteAction : public Action
{
public:
	//--- constructors
    WriteAction(const char *name);
    ~WriteAction();

    //!DoSomething method for configured Actions
	//! \param transitionToken (in/out) the event passed by the caller, can be modified.
	//! \param ctx the context the action runs within.
	//! \param config the configuration of the action.
	//! \return true if the action run successfully, false if an error occurred.
	virtual bool DoExecAction(String &transitionToken, Context& ctx, const ROAnything &config);

};

#endif
