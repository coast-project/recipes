/*
 * Copyright (c) 2000 itopia
 * All Rights Reserved
 *
 * OurActions:    executing custom actions
 *
 *
 *  $Id$
 */

#ifndef _OURACTIONS_H
#define _OURACTIONS_H

#ifdef __GNUG__
	#pragma interface
#endif

#if defined(__GNUG__) || defined(__SUNPRO_CC)
	#ident "@(#) $Id$ (c) itopia"
#else
	#define OurActions_H_ID "@(#) $Id$ (c) itopia"
#endif

//---- OurActions include -------------------------------------------------
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
