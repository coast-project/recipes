/*
 * Copyright (c) 2000 itopia
 * All Rights Reserved
 *
 * Role:   Role manages the transition from one page to the other
 *          assuming different roles for a user
 *
 *  $Id$
 */

#ifndef _OURROLE_H
#define _OURROLE_H

#ifdef __GNUG__
	#pragma interface
#endif

#if defined(__GNUG__) || defined(__SUNPRO_CC)
	#ident "@(#) $Id$ (c) itopia"
#else
	#define OurRoles_H_ID "@(#) $Id$ (c) itopia"
#endif

//---- OurRoles include -------------------------------------------------
#include "Role.h"
#include "config_recipes.h"

//---- GuestRole -------------------------------------------------------------------

class EXPORTDECL_RECIPES GuestRole : public Role {
public:
	GuestRole();
	GuestRole( const char *name);
	virtual bool Init(Context &c);
protected:
	IFAObject *Clone() const;
};

//---- AdminRole -------------------------------------------------------------------
class EXPORTDECL_RECIPES AdminRole : public Role {
public:
	AdminRole();
	AdminRole(const char *);
	virtual bool Init(Context &c);
protected:
	IFAObject *Clone() const;
};


//---- CustomerRole -------------------------------------------------------------------
class EXPORTDECL_RECIPES CustomerRole : public Role {
public:
	CustomerRole();
	CustomerRole(const char *name);
	virtual bool Init(Context &c);

protected:
	IFAObject *Clone() const;

};

#endif
