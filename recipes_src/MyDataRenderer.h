/*
 * Copyright (c) 2000 itopia
 * All Rights Reserved
 *
 * $Id$
 */

#ifndef _MyDataRenderer_H
#define _MyDataRenderer_H

#ifdef __GNUG__
	#pragma interface
#endif

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
	virtual void RenderAll(ostream &reply, Context &c, const ROAnything &config);

};

#endif
