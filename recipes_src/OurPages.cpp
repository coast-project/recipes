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
#include "OurPages.h"

#include "System.h"
#include "Dbg.h"

#if defined(__GNUG__) || defined(__SUNPRO_CC)
	#ident "@(#) $Id$ (c) itopia"
#else
	static char static_c_rcs_id[] = "@(#) $Id$ (c) itopia";
	static char static_h_rcs_id[] = OurPages_H_ID;
#endif

//---- OurPages --------------------------------------------------------------------------

//---- MyNewPage -------------------------------------------------------------------
RegisterPage(MyNewPage);

MyNewPage::MyNewPage()
	: Page("MyNewPage")
{
}

MyNewPage::MyNewPage(const char *title): Page(title)
{
}

IFAObject *MyNewPage::Clone() const
{
	return new MyNewPage();
}

bool MyNewPage::Postprocess(String &action, Context &c)
{
	StartTrace(MyNewPage.Postprocess); // "action: <" << NotNull(action) << ">");

	Anything query= c.GetQuery();

	Anything fields;
	if (query.LookupPath(fields, "fields")) {
		if ( !fields.IsDefined("myToggle")) {
			fields["myToggle"] = "off";
		}
	}

	return true; //Page::Postprocess(action, c);
}

void MyNewPage::Preprocess(Context &c)
{
	Page::Preprocess(c);
}

//---- MyAccountPage -------------------------------------------------------------------
RegisterPage(MyAccountPage);

MyAccountPage::MyAccountPage()
	: Page("MyAccountPage")
{
}

MyAccountPage::MyAccountPage(const char *title): Page(title)
{
}

IFAObject *MyAccountPage::Clone() const
{
	return new MyAccountPage();
}

bool MyAccountPage::Postprocess(String &action, Context &c)
{
	StartTrace(MyAccountPage.Postprocess);  //, "action: <" << NotNull(action) << ">");

	Anything query= c.GetQuery();

	Anything fields;
	if (query.LookupPath(fields, "fields")) {
		if ( !fields.IsDefined("myToggle")) {
			fields["myToggle"] = "off";
		}
	}

	return true; //Page::Postprocess(action, c);
}

void MyAccountPage::Preprocess(Context &c)
{
	Anything query=		c.GetQuery();
	Anything tmpStore=	c.GetTmpStore();

	// get some data from a file in Anything-format
	Anything input;
	iostream *is = System::OpenStream( "AccountData.any", 0 );
	if ( is != 0 ) {
		// opened ok; now read the content, close the file and store the data in tmpStore
		input.Import(*is);
		delete is; is = 0;

		tmpStore["AccountData"] = input;
	}

	Page::Preprocess(c);
}

//---- Ex4Page -------------------------------------------------------------------
RegisterPage(Ex4Page);

Ex4Page::Ex4Page()
	: Page("Ex4Page")
{
}

Ex4Page::Ex4Page(const char *title)
	: Page(title)
{
}

IFAObject *Ex4Page::Clone() const
{
	return new Ex4Page();
}

void Ex4Page::Preprocess(Context &c)
{

	Anything tmpStore=	c.GetTmpStore();

	// get some data from a file in Anything-format (recipe 20)
	Anything input;
	iostream *is = System::OpenStream( "AccountData.any", 0 );
	if ( is != 0 ) {
		// opened ok; now read the content, close the file and store the data in tmpStore
		input.Import(*is);
		delete is; is = 0;

		tmpStore["AccountData"] = input;
	}

	// get dynamically data such as the current time (recipe 25)
	time_t now;
	time( &now );
	struct tm *tt;
#ifdef WIN32
	tt= localtime(&now);
#else
	struct tm res;
	tt= localtime_r(&now, &res);
#endif

	char date[ 200 ];
	strftime( date, 100, "%C", tt );

	tmpStore["currentDate"] = date;

	Page::Preprocess(c);
}


//---- ViewPage -------------------------------------------------------------------
RegisterPage(ViewPage);

ViewPage::ViewPage()
	: Page("ViewPage")
{
}

ViewPage::ViewPage(const char *title)
	: Page(title)
{
}

IFAObject *ViewPage::Clone() const
{
	return new ViewPage();
}

void ViewPage::Preprocess(Context &c)
{
	Page::Preprocess(c);
}

void ViewPage::Mime(ostream &reply, Context &c)
{
	reply << "Content-type: text/plain\n";
}

void ViewPage::Header(ostream &reply, Context&)
{
}

void ViewPage::Title(ostream &reply, Context&)
{
	reply << "View config Files of this CookBook\n";
}

void ViewPage::Body(ostream &reply, Context&)
{
	reply << "...";
}
void ViewPage::Footer(ostream &reply, Context&)
{
//	reply.Append("powered by WebDisplay\n");
//	cerr << "powered by WebDisplay\n";
}


