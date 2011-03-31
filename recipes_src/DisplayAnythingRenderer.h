/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */

#ifndef _DisplayAnythingRenderer_H
#define _DisplayAnythingRenderer_H

#include "Renderer.h"
#include "config_recipes.h"

//---- DisplayAnythingRenderer ---------------------------------------------------------------

class EXPORTDECL_RECIPES DisplayAnythingRenderer : public Renderer {
public:
	DisplayAnythingRenderer(const char *name);
	void RenderAll(/*Reply*/ std::ostream &reply, Context &c, const ROAnything &config);
};

#endif
