/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */
#include "OurPages.h"
#include "System.h"
#include "Context.h"

RegisterPage(MyNewPage);

bool MyNewPage::Postprocess(String &action, Context &c) {
	StartTrace(MyNewPage.Postprocess); // "action: <" << NotNull(action) << ">");

	Anything query = c.GetQuery();

	Anything fields;
	if (query.LookupPath(fields, "fields")) {
		if (!fields.IsDefined("myToggle")) {
			fields["myToggle"] = "off";
		}
	}

	return true; //Page::Postprocess(action, c);
}

void MyNewPage::Preprocess(Context &c) {
	Page::Preprocess(c);
}
//---- MyAccountPage -------------------------------------------------------------------
RegisterPage(MyAccountPage);

bool MyAccountPage::Postprocess(String &action, Context &c) {
	StartTrace(MyAccountPage.Postprocess); //, "action: <" << NotNull(action) << ">");

	Anything query = c.GetQuery();

	Anything fields;
	if (query.LookupPath(fields, "fields")) {
		if (!fields.IsDefined("myToggle")) {
			fields["myToggle"] = "off";
		}
	}

	return true; //Page::Postprocess(action, c);
}

void MyAccountPage::Preprocess(Context &c) {
	Anything query = c.GetQuery();
	Anything tmpStore = c.GetTmpStore();

	// get some data from a file in Anything-format
	Anything input;
	std::iostream *is = System::OpenStream("AccountData.any", 0);
	if (is != 0) {
		// opened ok; now read the content, close the file and store the data in tmpStore
		input.Import(*is);
		delete is;
		is = 0;

		tmpStore["AccountData"] = input;
	}

	Page::Preprocess(c);
}
//---- Ex4Page -------------------------------------------------------------------
RegisterPage(Ex4Page);

void Ex4Page::Preprocess(Context &c) {

	Anything tmpStore = c.GetTmpStore();

	// get some data from a file in Anything-format (recipe 20)
	Anything input;
	std::iostream *is = System::OpenStream("AccountData.any", 0);
	if (is != 0) {
		// opened ok; now read the content, close the file and store the data in tmpStore
		input.Import(*is);
		delete is;
		is = 0;

		tmpStore["AccountData"] = input;
	}

	// get dynamically data such as the current time (recipe 25)
	time_t now;
	time(&now);
	struct tm *tt;
#ifdef WIN32
	tt= localtime(&now);
#else
	struct tm res;
	tt = localtime_r(&now, &res);
#endif

	char date[200];
	strftime(date, 100, "%C", tt);

	tmpStore["currentDate"] = date;

	Page::Preprocess(c);
}
//---- ViewPage -------------------------------------------------------------------
RegisterPage(ViewPage);

void ViewPage::Preprocess(Context &c) {
	Page::Preprocess(c);
}

void ViewPage::Mime(std::ostream &reply, Context &c) {
	reply << "Content-type: text/plain\n";
}

void ViewPage::Header(std::ostream &reply, Context&) {
}

void ViewPage::Title(std::ostream &reply, Context&) {
	reply << "View config Files of this CookBook\n";
}

void ViewPage::Body(std::ostream &reply, Context&) {
	reply << "...";
}
void ViewPage::Footer(std::ostream &reply, Context&) {
	//	reply.Append("powered by COAST\n");
	//	cerr << "powered by COAST\n";
}

