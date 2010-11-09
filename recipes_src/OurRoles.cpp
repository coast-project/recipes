/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */

//--- interface ------------
#include "OurRoles.h"

#include "System.h"
#include "Context.h"
#include "Dbg.h"

//---- GuestRole ---------------------------------------------------------------------
RegisterRole(GuestRole);

GuestRole::GuestRole()
	: Role("GuestRole")
{
}

GuestRole::GuestRole(const char *title): Role(title)
{
}

IFAObject *GuestRole::Clone(Allocator *a) const
{
	return new (a) GuestRole();
}

bool GuestRole::Init(Context &c)
{
	// store some Information in the role store
	Anything &roleStore= c.GetRoleStoreGlobal();
	String res;
	GetName( res );
	roleStore["MyRole"] = res;

	return true;
}

//---- AdminRole ---------------------------------------------------------------------
RegisterRole(AdminRole);

AdminRole::AdminRole()
: Role("AdminRole")
{
}

AdminRole::AdminRole(const char *title): Role(title)
{
}

IFAObject *AdminRole::Clone(Allocator *a) const
{
	return new (a) AdminRole();
}

bool AdminRole::Init(Context &c)
{
	return true;
}

//---- CustomerRole ---------------------------------------------------------------------
RegisterRole(CustomerRole);

CustomerRole::CustomerRole()
	: Role("CustomerRole")
{
}

CustomerRole::CustomerRole(const char *title): Role(title)
{
}

IFAObject *CustomerRole::Clone(Allocator *a) const
{
	return new (a) CustomerRole();
}

bool CustomerRole::Init(Context &c)
{
	StartTrace(CustomerRole.Init);
	Anything fields = c.GetQuery()["fields"];
	Anything &roleStore= c.GetRoleStoreGlobal();

	// store the personel Information in the role store
	roleStore["UserName"] 	= fields["resultLoginName"].AsString("");
	String res;
	GetName( res );
	roleStore["MyRole"] = res;

	return true;
}

