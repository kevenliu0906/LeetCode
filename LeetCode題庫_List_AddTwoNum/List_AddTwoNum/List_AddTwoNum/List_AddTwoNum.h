
// List_AddTwoNum.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CList_AddTwoNumApp:
// See List_AddTwoNum.cpp for the implementation of this class
//

class CList_AddTwoNumApp : public CWinApp
{
public:
	CList_AddTwoNumApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CList_AddTwoNumApp theApp;