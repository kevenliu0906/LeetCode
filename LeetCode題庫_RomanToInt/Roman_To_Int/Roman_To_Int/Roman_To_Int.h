
// Roman_To_Int.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CRoman_To_IntApp:
// See Roman_To_Int.cpp for the implementation of this class
//

class CRoman_To_IntApp : public CWinApp
{
public:
	CRoman_To_IntApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CRoman_To_IntApp theApp;