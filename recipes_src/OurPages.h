/*
 * Copyright (c) 2000 itopia
 * All Rights Reserved
 *
 * OurPages:    Subclasses of Page for our Examples
 *
 *  $Id$
 */

#ifndef _OURPAGES_H
#define _OURPAGES_H

#ifdef __GNUG__
	#pragma interface
#endif

#if defined(__GNUG__) || defined(__SUNPRO_CC)
	#ident "@(#) $Id$ (c) itopia"
#else
	#define OurPages_H_ID "@(#) $Id$ (c) itopia"
#endif

//---- OurPages include -------------------------------------------------
#include "Page.h"
#include "config_recipes.h"

class Context;
class Role;
class Session;
class String;

//---- MyNewPage -------------------------------------------------------------------

class EXPORTDECL_RECIPES MyNewPage : public Page {
public:
	MyNewPage();
	MyNewPage(const char *name);
	IFAObject *Clone() const;
	void Preprocess(Context&);
	virtual bool Postprocess(String &action, Context &c);
};

//---- MyAccountPage -------------------------------------------------------------------

class EXPORTDECL_RECIPES MyAccountPage : public Page {
public:
	MyAccountPage();
	MyAccountPage(const char *name);
	IFAObject *Clone() const;
	void Preprocess(Context&);
	virtual bool Postprocess(String &action, Context &c);
};

//---- Ex4Page -------------------------------------------------------------------

class EXPORTDECL_RECIPES Ex4Page : public Page {
public:
	Ex4Page();
	Ex4Page(const char *title);

	IFAObject *Clone() const;
	virtual void Preprocess(Context&);
};

//---- ViewPage -------------------------------------------------------------------

class EXPORTDECL_RECIPES ViewPage : public Page {
public:
	ViewPage();
	ViewPage(const char *title);

	IFAObject *Clone() const;
	virtual void Preprocess(Context&);
	virtual void Mime(ostream &reply, Context &c);
	virtual void Header(ostream &reply, Context&);
	virtual void Title(ostream &reply, Context&);
	virtual void Body(ostream &reply, Context&);
	virtual void Footer(ostream &reply, Context&);
};

#endif
