/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */

#ifndef _OURROLE_H
#define _OURROLE_H

#include "Role.h"

//---- GuestRole -------------------------------------------------------------------

class GuestRole : public Role {
public:
	GuestRole();
	GuestRole( const char *name);
	virtual bool Init(Context &c);
protected:
	/*! @copydoc IFAObject::Clone(Allocator *) */
	IFAObject *Clone(Allocator *a) const;
};

//---- AdminRole -------------------------------------------------------------------
class AdminRole : public Role {
public:
	AdminRole();
	AdminRole(const char *);
	virtual bool Init(Context &c);
protected:
	/*! @copydoc IFAObject::Clone(Allocator *) */
	IFAObject *Clone(Allocator *a) const;
};

//---- CustomerRole -------------------------------------------------------------------
class CustomerRole : public Role {
public:
	CustomerRole();
	CustomerRole(const char *name);
	virtual bool Init(Context &c);

protected:
	/*! @copydoc IFAObject::Clone(Allocator *) */
	IFAObject *Clone(Allocator *a) const;

};

#endif
