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
#include "ButtonAppletRenderer.h"

#include "Dbg.h"
#include <cstring>

//---- ButtonAppletRenderer --------------------------------------------------------------

RegisterRenderer(ButtonAppletRenderer);

ButtonAppletRenderer::ButtonAppletRenderer(const char *name) : Renderer(name)
{
};

void ButtonAppletRenderer::RenderAll(/*Reply*/ std::ostream &reply, Context &c, const ROAnything &config)
{
	StartTrace(ButtonAppletRenderer.RenderAll);
	TraceAny(config,"Config");

	Anything codeBase= c.Lookup("CodeBase", "./");
	Anything appletCode= c.Lookup("AppletCode", "./");

	TraceAny(codeBase,"codeBase");
	TraceAny(appletCode,"appletCode");

	reply << "<APPLET codebase=\"" << codeBase.AsCharPtr()
		<< "\" code=\"" << appletCode.AsCharPtr() << "\" "
		<< config["Options"].AsCharPtr("width=300 height=200") << ">";

	if (config.IsDefined("Params")) {
		ROAnything params= config["Params"];
		for (long j= 0; j<params.GetSize(); j++) {
			const char *name= params.SlotName(j);
			// Cha STR 19.1.98
			String value;
			String rValue;
			{
			 /*Reply*/ OStringStream r(&rValue);
			 Render(r,c,params[name]);
			}
			// Special format for ButtonAppletRenderer!!
			if ( (strcmp( name, "url") == 0) && (params[name].IsDefined("BuildBase")) ) {
				if ( params[name]["BuildBase"] == "1" ) {
					ROAnything env(c.GetEnvStore());
					if ( strcmp ( env["HTTP_HOST"].AsCharPtr(""), "" ) == 0 ) {
						const char *baseAddr= 0;
						baseAddr= c.Lookup("BaseAddress", (const char *)0);
						value << baseAddr << "/";;
					} else {
						value << "http://" << env["HTTP_HOST"].AsCharPtr("");
					}
					if ( strcmp ( env["SCRIPT_NAME"].AsCharPtr(""), "" ) != 0 )
						value << env["SCRIPT_NAME"].AsCharPtr("") << "/";

				}
			}
			value.Append(rValue);
			reply << "<PARAM name=" << name << " value=\"" << value << "\">";
			// Che STR 19.1.98
		}
	}

	reply << "</APPLET>";
}
