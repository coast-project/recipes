/*
 * Copyright (c) 2009, Peter Sommerlad and IFS Institute for Software at HSR Rapperswil, Switzerland
 * All rights reserved.
 *
 * This library/application is free software; you can redistribute and/or modify it under the terms of
 * the license that is included with this library/application in the file license.txt.
 */

#ifndef _CONFIG_RECIPES_H
#define _CONFIG_RECIPES_H

// WIN32 settings for Windows NT
#if defined(WIN32)
#	ifdef _DLL
#		ifdef RECIPES_IMPL
#			define EXPORTDECL_RECIPES	__declspec(dllexport)
#		else
#			define EXPORTDECL_RECIPES	__declspec(dllimport)
#		endif
#	else
#		define EXPORTDECL_RECIPES
#	endif
#else
#	define EXPORTDECL_RECIPES
#endif

#endif
