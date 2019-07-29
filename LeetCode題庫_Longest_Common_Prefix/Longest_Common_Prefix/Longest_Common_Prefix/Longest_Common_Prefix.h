
// Longest_Common_Prefix.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLongest_Common_PrefixApp:
// See Longest_Common_Prefix.cpp for the implementation of this class
//

class CLongest_Common_PrefixApp : public CWinApp
{
public:
	CLongest_Common_PrefixApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLongest_Common_PrefixApp theApp;