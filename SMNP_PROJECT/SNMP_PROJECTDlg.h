
// SMNP_PROJECTDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CSMNP_PROJECTDlg dialog
class CSMNP_PROJECTDlg : public CDHtmlDialog
{
// Construction
public:
	CSMNP_PROJECTDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SMNP_PROJECT_DIALOG, IDH = IDR_HTML_SMNP_PROJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	afx_msg void OnBnClickedIdcButton();
	afx_msg void OnCheckButton();
	afx_msg void OnButtonExit();

private:
	void InitVar();
	BOOL CheckConnectToAgent();
	BOOL CheckInput();
	BOOL GetDataFromAgent(CString szServerIP, CString szPort, CString szComunity,CString szTree, CString& szResult);
public:
	CString m_szIPServer;
	CString m_szPortServer;
	CString m_szComunity;
	BOOL	m_bServerAvailable;
	CEdit m_EditServerIP;
	CEdit m_EditServerPort;
	CEdit m_EditComunity;
};
