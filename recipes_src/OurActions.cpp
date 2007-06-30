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
#include "OurActions.h"

#include "Context.h"
#include "Dbg.h"
#include "System.h"

#if defined(__GNUG__) || defined(__SUNPRO_CC)
	#ident "@(#) $Id$ (c) itopia"
#else
	static char static_c_rcs_id[] = "@(#) $Id$ (c) itopia";
	static char static_h_rcs_id[] = OurActions_H_ID;
#endif

//---- RecipeAction -------------------------------------------------------------------
RegisterAction(RecipeAction);

RecipeAction::RecipeAction(const char *name):  Action(name)
{
}

bool RecipeAction::DoAction(String &action, Context &c)
{
	Anything query= c.GetQuery();

	StartTrace(RecipeAction.DoAction);	// debugging
	TraceAny(query, "query");

	Anything result;

	if ( query.IsDefined("WhichRecipe")) {
		String templateName = query["WhichRecipe"].AsString("");

		Anything tmpStore= c.GetTmpStore();
		tmpStore["WhichRecipe"]= templateName;
		action = "GoRecipesPage";
		return true;
	}
	action = "Home";
	return true;
}


//---- MyFormAction -------------------------------------------------------------------
RegisterAction(MyFormAction);

MyFormAction::MyFormAction(const char *name):  Action(name)
{
}

bool MyFormAction::DoAction(String &action, Context &c)
{
	Anything query= c.GetQuery();
	Anything fields = query["fields"];

	StartTrace(MyFormAction.DoAction);	// debugging
	TraceAny(query, "query");

	// Using the example above fields will look like this
	//	/MyButton	"Press Me"
	//	/MyFirstField "Whatever has been entered in this field"
	//	/MySecondField	"on"  if checked oterwise it isn't there

	// code to handle the input
	// ....

	// in order to see the values on another page you should store it in the role or temp store
	// since that's not to do in this recipe we will just show some text
	// (temp store for one request - role store for the whole time you are in the same role)
	Anything &rs= c.GetRoleStoreGlobal();
	rs["MyFirstField"] 	= "you didn't store your values in this recipe, so you forgott this value";
	rs["MySecondField"] = "you didn't store your values in this recipe, so you forgott this value";

	action = "MyFormAction";	// "MyFormAction" must be a name of an action defined in /Map in role.any
	return true;
}

//---- MyCheckFormAction -------------------------------------------------------------------
RegisterAction(MyCheckFormAction);

MyCheckFormAction::MyCheckFormAction(const char *name):  Action(name)
{
}

bool MyCheckFormAction::DoAction(String &action, Context &c)
{
	Anything query= c.GetQuery();
	Anything fields = query["fields"];

	StartTrace(MyCheckFormAction.DoAction);	// debugging
	TraceAny(query, "query");

	// Using the example above fields will look like this
	//	/MyButton	"Press Me"
	//	/MyFirstField "Whatever has been entered in this field"
	//	/MySecondField	"on"  if checked oterwise it isn't there

	// code to handle the input
	// store the content of the fields in the role store for later use
	Anything &rs =c.GetRoleStoreGlobal();
	rs["MySecondField"] = "not checked and therefore not here";
	for (int i = 0; i < fields.GetSize(); i++) {
		// all the fields should be stored directly, because Context.Lookup
		// can't find MyNextFormData.MyFirstField
		rs[fields.SlotName(i)] = fields[i];
	}

	// launch confirmation page
	action = "MyCheckFormAction";
	return true;
}


//---- MyConfirmationAction -------------------------------------------------------------------
RegisterAction(MyConfirmationAction);

MyConfirmationAction::MyConfirmationAction(const char *name):  Action(name)
{
}

bool MyConfirmationAction::DoAction(String &action, Context &c)
{
	Anything query= c.GetQuery();
	Anything fields = query["fields"];

	StartTrace(MyConfirmationAction.DoAction);	// debugging
	TraceAny(query, "query");


	// Check if OkButton was pressed
	if (fields.IsDefined("OkButton")) {
		// Retrieve the fields from the RoleStore
		ROAnything rs = c.GetRoleStoreGlobal();

		// ... and perform what you like to do in the Ok case
		String firstFirst 	= rs["MyFirstField"].AsString("");  // just for fun
		String secondFirst 	= rs["MySecondField"].AsString(""); // just for fun
		action = "InputOk";
		return true;
	}
	// NokButton pressed: delete the content of the fields in the role store
	Anything &rs= c.GetRoleStoreGlobal();
	rs["MyFirstField"] 	= "you have not confirmed the entries";
	rs["MySecondField"]	= "you have not confirmed the entries";

	action = "InputNok";
	return true;
}

//---- MyGoBackAction -------------------------------------------------------------------
RegisterAction(MyGoBackAction);

MyGoBackAction::MyGoBackAction(const char *name):  Action(name)
{
}

bool MyGoBackAction::DoAction(String &action, Context &c)
{
	Anything query= c.GetQuery();
	Anything fields = query["fields"];

	StartTrace(MyGoBackAction.DoAction);	// debugging
	TraceAny(query, "query");

	// delete the content of the fields in the role store
	Anything &rs= c.GetRoleStoreGlobal();
	if ( rs.IsDefined("MyFirstField")) {
		rs.Remove("MyFirstField");
	}
	if ( rs.IsDefined("MySecondField")) {
		rs.Remove("MySecondField");
	}
	if ( rs.IsDefined("MyButton")) {
		rs.Remove("MyButton");
	}
	action = "GoBack";
	return true;
}

//---- MyDoCheckPassword -------------------------------------------------------------------
RegisterAction(MyDoCheckPassword);

MyDoCheckPassword::MyDoCheckPassword(const char *name):  Action(name)
{
}

bool MyDoCheckPassword::DoAction(String &action, Context &c)
{
	Anything fields = c.GetQuery()["fields"];

	StartTrace(MyDoCheckPassword.DoAction);	// debugging
	TraceAny(fields, "fields");

	// make the needed checks
	String name = fields["resultLoginName"].AsString("");
	String password = fields["resultPassword"].AsString("");

	if ( password == "mypass" ) {
		   action = "LoginOk";
		   return true;
	   }
	action = "Login";  // just try the login again
	return true;
}

//---- DoSomething -------------------------------------------------------------------
RegisterAction(DoSomething);

DoSomething::DoSomething(const char *name):  Action(name)
{
}

bool DoSomething::DoAction(String &action, Context &c)
{
	Anything query = c.GetQuery();

	StartTrace(DoSomething.DoAction);	// debugging
	TraceAny(query, "query");

	// make the wanted checks
	Anything result;
	if (query.LookupPath( result, "fields.loginname" )) {
		String thatsthename = result.AsString("");
		if ( thatsthename.Length() ) {
			Anything tmpStore = c.GetTmpStore();

			tmpStore["thatsthename"] = thatsthename;
			if (thatsthename == "Markus") {
				action = "GoExample4";
				return true;
			}
		}
	}
	action = "GoExample4";
	return true;
}
