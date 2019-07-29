
// Contain_MaxWater.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CContain_MaxWaterApp:
// See Contain_MaxWater.cpp for the implementation of this class
//

class CContain_MaxWaterApp : public CWinApp
{
public:
	CContain_MaxWaterApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CContain_MaxWaterApp theApp;