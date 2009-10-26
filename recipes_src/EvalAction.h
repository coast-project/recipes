/*
 * Copyright (c) 2000 itopia
 * All Rights Reserved
 *
 * EvalAction:
 *
 * $Id$
 */

#ifndef _EvalAction_H
#define _EvalAction_H

#ifdef __GNUG__
	#pragma interface
#endif

//---- Action include -------------------------------------------------
#include "Action.h"
#include "config_recipes.h"

//---- EvalAction ----------------------------------------------------------
//! comment action
//!	Structure of config:
//!<PRE>	{
//!		/Slot1	....
//!      ...
//!	}</PRE>
class EXPORTDECL_RECIPES EvalAction : public Action
{
public:
	//--- constructors
    EvalAction(const char *name);
    ~EvalAction();

    //!DoSomething method for configured Actions
	//! \param transitionToken (in/out) the event passed by the caller, can be modified.
	//! \param ctx the context the action runs within.
	//! \param config the configuration of the action.
	//! \return true if the action run successfully, false if an error occurred.
	virtual bool DoExecAction(String &transitionToken, Context& ctx, const ROAnything &config);

};

#endif
