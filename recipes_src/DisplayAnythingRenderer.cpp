/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */

#include "DisplayAnythingRenderer.h"
#include "StringStream.h"

//---- DisplayAnythingRenderer --------------------------------------------------------------
RegisterRenderer(DisplayAnythingRenderer);

DisplayAnythingRenderer::DisplayAnythingRenderer(const char *name) : Renderer(name)
{
};

void DisplayAnythingRenderer::RenderAll(/*Reply*/ std::ostream &reply, Context &c, const ROAnything &config)
{
	Anything anythingToPrint = config["AnythingInfo"].DeepClone();

	String replyStr;
	{	// block is cruicial for flushing of stream! (otherwise it need to be flushed explicitly)
		OStringStream replyStream(&replyStr);
		replyStream << anythingToPrint;
	}

	String replyStrNew, tmp;
	for ( long i = 0; i < replyStr.Length(); i++ )
	{
		//: create a new String containing a part of this
		//!param: start - character index to start from >= 0
		//!param: length - how many characters come into the new string <0 means to the end
		switch ( replyStr[i]  )
		{
			case ' '	: replyStrNew = replyStrNew.Append("&nbsp;"); break;
			case '\\' 	: tmp = replyStr.SubString(i+1, 3);
						  if ( tmp.IsEqual( "x09" ) )
						  {
							  replyStrNew = replyStrNew.Append("&nbsp;&nbsp;&nbsp;");
							  i += 3;
						  }
						  break;
			case '"'	: break;	// desired " must be escaped with &#34;
			default		: replyStrNew = replyStrNew.Append(replyStr[i]); break;
		}
	}

	// Cut till the first "{" and from the last "}" till end-of-string
	//-----------------------------------------------------------------
	// 1) find index of first occurance of character "{"
	long  firstPos =  replyStrNew.StrChr( '{' ) + 1;
	// 2) find index of last occurance of character "}"
	long lastPos = replyStrNew.StrRChr( '}' ) - 1;
	// 3) create a new String containing a part of this
	replyStrNew = replyStrNew.SubString( firstPos, lastPos - firstPos );

	// Set the result
	reply << replyStrNew;
}

