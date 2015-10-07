
// SMNP_PROJECT.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSMNP_PROJECTApp:
// See SMNP_PROJECT.cpp for the implementation of this class
//

class CSMNP_PROJECTApp : public CWinAppEx
{
public:
	CSMNP_PROJECTApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSMNP_PROJECTApp theApp;