/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */

#ifndef _OURACTIONS_H
#define _OURACTIONS_H

#include "Action.h"
#include "config_recipes.h"

class Context;
class Role;
class Session;

//---- RecipeAction -------------------------------------------------------------------

class EXPORTDECL_RECIPES RecipeAction : public Action {
public:
	RecipeAction(const char *name);
	bool DoAction(String &action, Context &c);
};

//---- MyFormAction -------------------------------------------------------------------

class EXPORTDECL_RECIPES MyFormAction : public Action {
public:
	MyFormAction(const char *name);
	bool DoAction(String &action, Context &c);
};

//---- MyNextFormAction -------------------------------------------------------------------

class EXPORTDECL_RECIPES MyCheckFormAction : public Action {
public:
	MyCheckFormAction(const char *name);
	bool DoAction(String &action, Context &c);
};

//---- MyConfirmationAction -------------------------------------------------------------------

class EXPORTDECL_RECIPES MyConfirmationAction : public Action {
public:
	MyConfirmationAction(const char *name);
	bool DoAction(String &action, Context &c);
};

//---- MyGoBackAction -------------------------------------------------------------------

class EXPORTDECL_RECIPES MyGoBackAction : public Action {
public:
	MyGoBackAction(const char *name);
	bool DoAction(String &action, Context &c);
};

//---- MyDoCheckPassword -------------------------------------------------------------------

class EXPORTDECL_RECIPES MyDoCheckPassword : public Action {
public:
	MyDoCheckPassword(const char *name);
	bool DoAction(String &action, Context &c);
};

//---- DoSomething -------------------------------------------------------------------

class EXPORTDECL_RECIPES DoSomething : public Action {
public:
	DoSomething(const char *name);
	bool DoAction(String &action, Context &c);
};

#endif
