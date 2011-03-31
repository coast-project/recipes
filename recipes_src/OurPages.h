/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */

#ifndef _OURPAGES_H
#define _OURPAGES_H

#include "Page.h"

class Context;
class Role;
class Session;
class String;

class MyNewPage: public Page {
public:
	MyNewPage() :
		Page("MyNewPage") {
	}
	MyNewPage(const char *name) :
		Page(name) {
	}
	/*! @copydoc IFAObject::Clone(Allocator *) */
	IFAObject *Clone(Allocator *a) const {
		return new (a) MyNewPage();
	}
	void Preprocess(Context&);
	virtual bool Postprocess(String &action, Context &c);
};

//---- MyAccountPage -------------------------------------------------------------------

class MyAccountPage: public Page {
public:
	MyAccountPage() :
		Page("MyAccountPage") {
	}
	MyAccountPage(const char *name) :
		Page(name) {
	}
	/*! @copydoc IFAObject::Clone(Allocator *) */
	IFAObject *Clone(Allocator *a) const {
		return new (a) MyAccountPage();
	}
	void Preprocess(Context&);
	virtual bool Postprocess(String &action, Context &c);
};

//---- Ex4Page -------------------------------------------------------------------

class Ex4Page: public Page {
public:
	Ex4Page() :
		Page("Ex4Page") {
	}
	Ex4Page(const char *title) :
		Page(title) {
	}
	/*! @copydoc IFAObject::Clone(Allocator *) */
	IFAObject *Clone(Allocator *a) const {
		return new (a) Ex4Page();
	}
	virtual void Preprocess(Context&);
};

//---- ViewPage -------------------------------------------------------------------

class ViewPage: public Page {
public:
	ViewPage() :
		Page("ViewPage") {
	}
	ViewPage(const char *title) :
		Page(title) {
	}
	/*! @copydoc IFAObject::Clone(Allocator *) */
	IFAObject *Clone(Allocator *a) const {
		return new (a) ViewPage();
	}
	virtual void Preprocess(Context&);
	virtual void Mime(std::ostream &reply, Context &c);
	virtual void Header(std::ostream &reply, Context&);
	virtual void Title(std::ostream &reply, Context&);
	virtual void Body(std::ostream &reply, Context&);
	virtual void Footer(std::ostream &reply, Context&);
};

#endif
