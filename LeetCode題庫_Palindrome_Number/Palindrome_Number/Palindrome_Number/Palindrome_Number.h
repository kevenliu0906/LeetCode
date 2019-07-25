
// Palindrome_Number.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPalindrome_NumberApp:
// See Palindrome_Number.cpp for the implementation of this class
//

class CPalindrome_NumberApp : public CWinApp
{
public:
	CPalindrome_NumberApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPalindrome_NumberApp theApp;