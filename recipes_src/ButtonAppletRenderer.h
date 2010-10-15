/*
 * Copyright (c) 2000 itopia
 * All Rights Reserved
 *
 * ButtonAppletRenderer:   Renderer Object for ButtonApplets
 *
 *  $Id$
 */

#ifndef _ButtonAppletRenderer_H
#define _ButtonAppletRenderer_H

#ifdef __GNUG__
	#pragma interface
#endif

//---- ButtonAppletRenderer include -------------------------------------------------
#include "Renderer.h"
#include "config_recipes.h"

//---- ButtonAppletRenderer ---------------------------------------------------------------

class EXPORTDECL_RECIPES ButtonAppletRenderer : public Renderer {
public:
	ButtonAppletRenderer(const char *name);
	void RenderAll(std::ostream &reply, Context &c, const ROAnything &config);
};

#endif
