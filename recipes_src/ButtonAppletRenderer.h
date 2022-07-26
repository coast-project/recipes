/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */

#ifndef _ButtonAppletRenderer_H
#define _ButtonAppletRenderer_H

#include "Renderer.h"

//---- ButtonAppletRenderer ---------------------------------------------------------------

class ButtonAppletRenderer : public Renderer {
public:
	ButtonAppletRenderer(const char *name);
	void RenderAll(std::ostream &reply, Context &c, const ROAnything &config);
};

#endif
