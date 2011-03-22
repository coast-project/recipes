/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */

#include "MyDataRenderer.h"
#include "Session.h"
#include "Page.h"
#include "Role.h"

//---- MyDataRenderer ---------------------------------------------------------------
RegisterRenderer(MyDataRenderer);

MyDataRenderer::MyDataRenderer(const char *name) : Renderer(name) { }

MyDataRenderer::~MyDataRenderer() { }

void MyDataRenderer::RenderAll(std::ostream &reply, Context &c, const ROAnything &config)
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
