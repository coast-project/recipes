/*
 * Copyright (c) 2000 itopia
 * All Rights Reserved
 *
 * DisplayAnythingRenderer
 *
 *  $Id$
 */

#ifndef _DisplayAnythingRenderer_H
#define _DisplayAnythingRenderer_H

#ifdef __GNUG__
	#pragma interface
#endif

//---- DisplayAnythingRenderer include -------------------------------------------------
#include "Renderer.h"
#include "config_recipes.h"

//---- DisplayAnythingRenderer ---------------------------------------------------------------

class EXPORTDECL_RECIPES DisplayAnythingRenderer : public Renderer {
public:
	DisplayAnythingRenderer(const char *name);
	void RenderAll(/*Reply*/ std::ostream &reply, Context &c, const ROAnything &config);
};

#endif
