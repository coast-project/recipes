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

class Context;
class Role;
class Session;

//---- RecipeAction -------------------------------------------------------------------

class RecipeAction : public Action {
public:
	RecipeAction(const char *name);
	bool DoAction(String &action, Context &c);
};

//---- MyFormAction -------------------------------------------------------------------

class MyFormAction : public Action {
public:
	MyFormAction(const char *name);
	bool DoAction(String &action, Context &c);
};

//---- MyNextFormAction -------------------------------------------------------------------

class MyCheckFormAction : public Action {
public:
	MyCheckFormAction(const char *name);
	bool DoAction(String &action, Context &c);
};

//---- MyConfirmationAction -------------------------------------------------------------------

class MyConfirmationAction : public Action {
public:
	MyConfirmationAction(const char *name);
	bool DoAction(String &action, Context &c);
};

//---- MyGoBackAction -------------------------------------------------------------------

class MyGoBackAction : public Action {
public:
	MyGoBackAction(const char *name);
	bool DoAction(String &action, Context &c);
};

//---- MyDoCheckPassword -------------------------------------------------------------------

class MyDoCheckPassword : public Action {
public:
	MyDoCheckPassword(const char *name);
	bool DoAction(String &action, Context &c);
};

//---- DoSomething -------------------------------------------------------------------

class DoSomething : public Action {
public:
	DoSomething(const char *name);
	bool DoAction(String &action, Context &c);
};

#endif
