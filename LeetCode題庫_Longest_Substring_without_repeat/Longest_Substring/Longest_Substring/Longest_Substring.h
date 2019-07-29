
// Longest_Substring.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLongest_SubstringApp:
// See Longest_Substring.cpp for the implementation of this class
//

class CLongest_SubstringApp : public CWinApp
{
public:
	CLongest_SubstringApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLongest_SubstringApp theApp;