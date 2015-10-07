#pragma once
#include "afxwin.h"

#ifdef _WIN32_WCE
#error "CDHtmlDialog is not supported for Windows CE."
#endif 

// CGetInfo dialog

class CGetInfo : public CDHtmlDialog
{
	DECLARE_DYNCREATE(CGetInfo)

public:
	CGetInfo(CWnd* pParent = NULL);   // standard constructor
	virtual ~CGetInfo();
// Overrides
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// Dialog Data
	enum { IDD = GETINFO_IDD_DIALOG, IDH = IDR_HTML_GETINFO1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	afx_msg void OnBnClickedIdok();

public:
	
	CString m_szSysDescr;
	CString	m_szSysObjectID;
	CString	m_szSysUpTime;
	CString	m_szSysContact;
	CString	m_szSysName;
	CString	m_szSysLocation;
	CString	m_szSysServices;
	CString m_szSysORLastChange;
	CEdit m_EditSysDescr;
	CEdit m_EditSysObjectID;
	CEdit m_EditSysUptime;
	CEdit m_EditContact;
	CEdit m_EditName;
	CEdit m_EditLocation;
	CEdit m_EditServices;
	CEdit m_EditORLastchange;
	afx_msg void OnBnClickedIdcancel();
};
