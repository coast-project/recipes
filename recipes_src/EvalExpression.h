/*
 * Copyright (c) 1999 itopia
 * All Rights Reserved
 *
 * EvalExpression:
 *
 *
 */
//! Id="$Id$" lib="library.so"

#ifndef _EvalExpression_H
#define _EvalExpression_H

#ifdef __GNUG__
	#pragma interface
#endif

//---- Action include -------------------------------------------------
#include "Action.h"
#include "config_recipes.h"

//---- EvalExpression ----------------------------------------------------------
//! action that evaluates a renderer expression on a given page in a given role with some additional state in tmpstore
//!	Structure of config:
//!<PRE>	{
//!		/RendererSlot	{} # renderer spec defining the location of the renderer anything as string
//!      /StateSlot		{} # renderer spec defining the location of additional state anything as string
//!	}</PRE>
class EXPORTDECL_RECIPES EvalExpression : public Action
{
public:
	//--- constructors
    EvalExpression(const char *name);
    ~EvalExpression();

    //!evaluate a renderer in a given context method for configured Actions
	//! \param transitionToken (in/out) the event passed by the caller, can be modified.
	//! \param ctx the context the action runs within.
	//! \param config the configuration of the action.
	//! \return true if the action run successfully, false if an error occurred.
	virtual bool DoExecAction(String &transitionToken, Context& ctx, const ROAnything &config);

};

#endif
