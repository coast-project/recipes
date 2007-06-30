/*
 * Copyright (c) 1999 itopia
 * All Rights Reserved
 *
 * ReadWriteAction:
 *
 * $Id$
 */

#ifndef _ReadWriteAction_H
#define _ReadWriteAction_H

#ifdef __GNUG__
	#pragma interface
#endif

#if defined(__GNUG__) || defined(__SUNPRO_CC)
	#ident "@(#) $Id$ (c) itopia"
#else
	#define ReadWriteAction_H_ID "@(#) $Id$ (c) itopia"
#endif

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
