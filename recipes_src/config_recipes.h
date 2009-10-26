/*
 * Copyright (c) 1999-2000 itopia
 * All Rights Reserved
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
