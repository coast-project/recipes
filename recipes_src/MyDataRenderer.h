/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */

#ifndef _MyDataRenderer_H
#define _MyDataRenderer_H

//---- Renderer include -------------------------------------------------
#include "Renderer.h"
#include "config_recipes.h"

//---- MyDataRenderer ----------------------------------------------------------
//! comment Renderer
//!	Structure of config:
//!<PRE>	{
//!		/Slot1	....
//!      ...
//!	}</PRE>
class EXPORTDECL_RECIPES MyDataRenderer : public Renderer
{
public:
	//--- constructors
    MyDataRenderer(const char *name);
    ~MyDataRenderer();

    //!Renders ?? on <I>reply </I>
	//! \param reply out - the stream where the rendered output is written on.
	//! \param c the context the renderer runs within.
	//! \param config the configuration of the renderer.
	virtual void RenderAll(std::ostream &reply, Context &c, const ROAnything &config);

};

#endif
