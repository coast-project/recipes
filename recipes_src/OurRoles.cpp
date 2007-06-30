/*
 * Copyright (c) 2000 itopia
 * All Rights Reserved
 *
 *  $Id$
 */

#ifdef __GNUG__
#pragma implementation
#endif

//--- interface ------------
#include "OurRoles.h"

#include "System.h"
#include "Context.h"
#include "Dbg.h"

#if defined(__GNUG__) || defined(__SUNPRO_CC)
	#ident "@(#) $Id$ (c) itopia"
#else
	static char static_c_rcs_id[] = "@(#) $Id$ (c) itopia";
	static char static_h_rcs_id[] = OurRoles_H_ID;
#endif

//---- GuestRole ---------------------------------------------------------------------
RegisterRole(GuestRole);

GuestRole::GuestRole()
	: Role("GuestRole")
{
}

GuestRole::GuestRole(const char *title): Role(title)
{
}

IFAObject *GuestRole::Clone() const
{
	return new GuestRole();
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

IFAObject *AdminRole::Clone() const
{
	return new AdminRole();
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

IFAObject *CustomerRole::Clone() const
{
	return new CustomerRole();
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

