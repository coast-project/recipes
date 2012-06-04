/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */

//! Id="$Id$" lib="library.so"

#ifndef _EvalExpression_H
#define _EvalExpression_H

#include "Action.h"

//---- EvalExpression ----------------------------------------------------------
//! action that evaluates a renderer expression on a given page in a given role with some additional state in tmpstore
//!	Structure of config:
//!<PRE>	{
//!		/RendererSlot	{} # renderer spec defining the location of the renderer anything as string
//!      /StateSlot		{} # renderer spec defining the location of additional state anything as string
//!	}</PRE>
class EvalExpression : public Action
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
