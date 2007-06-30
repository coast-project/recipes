/*
 * Copyright (c) 2000 itopia
 * All Rights Reserved
 *
 * $Id$
 */

#ifdef __GNUG__
#pragma implementation
#endif

//--- interface ------------
#include "MyDataRenderer.h"

#include "Dbg.h"
#include "Session.h"
#include "Role.h"
#include "Page.h"

#if defined(__GNUG__) || defined(__SUNPRO_CC)
	#ident "@(#) $Id$ (c) itopia"
#else
	static char static_c_rcs_id[] = "@(#) $Id$ (c) itopia";
	static char static_h_rcs_id[] = MyDataRenderer_H_ID;
#endif

//---- MyDataRenderer ---------------------------------------------------------------

RegisterRenderer(MyDataRenderer);

MyDataRenderer::MyDataRenderer(const char *name) : Renderer(name) { }

MyDataRenderer::~MyDataRenderer() { }

void MyDataRenderer::RenderAll(ostream &reply, Context &c, const ROAnything &config)
{
	StartTrace(MyDataRenderer.RenderAll);
	Session *s= c.GetSession();
	if (s)
	{
		reply << "<pre>Data from MyDataRenderer.cpp:\n";
		reply << "Session-Nummer : " << s->GetId() << "\n";
		reply << "Access-Counter : " << s->GetAccessCounter() << "\n";
		reply << "Access-Time    : " << s->GetAccessTime() << "\n";
	}
	Page *page= c.GetPage();
	if (page) {
		String pName;
		page->GetName(pName);
		reply << "Actual Page    : " << pName << "\n";
	}
	String rName("None");
	Role *r= c.GetRole();
	if (r)
		r->GetName(rName);
	reply << "Actual Role    : " << rName << "\n";

	reply << "Last Page      : " << c.Lookup("page") << "\n";
	reply << "Last Role      : " << c.Lookup("role") << "\n";
	reply << "Last Action    : " << c.Lookup("action") << "\n";

	reply << "</pre>";
}
