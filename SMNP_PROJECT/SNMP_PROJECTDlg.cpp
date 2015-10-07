
// SMNP_PROJECTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CSNMP_PROJECTApp.h"
#include "SNMP_PROJECTDlg.h"
#include "Winsnmp.h"
#include "SNMPManager.h"
#include "SNMPRemoteAgent.h"
#include "SNMPRemoteAgentSet.h"
#include "SNMPRequest.h"
#include "SNMPRequestSet.h"
#include "SNMPObject.h"
#include "SNMPException.h"
#include "GetInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSMNP_PROJECTDlg dialog

BEGIN_DHTML_EVENT_MAP(CSMNP_PROJECTDlg)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()



CSMNP_PROJECTDlg::CSMNP_PROJECTDlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CSMNP_PROJECTDlg::IDD, CSMNP_PROJECTDlg::IDH, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSMNP_PROJECTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_Control(pDX, SERVER_IDC_EDIT, m_EditServerIP);
	DDX_Control(pDX, PORT_IDC_EDIT, m_EditServerPort);
	DDX_Control(pDX, COMUNITY_IDC_STATIC, m_EditComunity);
}

BEGIN_MESSAGE_MAP(CSMNP_PROJECTDlg, CDHtmlDialog)
	ON_WM_SYSCOMMAND()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(CHECK_IDC_BUTTON, &CSMNP_PROJECTDlg::OnCheckButton)
	ON_BN_CLICKED(EXIT_IDC_BUTTON, &CSMNP_PROJECTDlg::OnButtonExit)
	ON_BN_CLICKED(GETINFO_IDC_BUTTON, &CSMNP_PROJECTDlg::OnBnClickedIdcButton)
END_MESSAGE_MAP()


// CSMNP_PROJECTDlg message handlers

BOOL CSMNP_PROJECTDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	InitVar();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSMNP_PROJECTDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDHtmlDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSMNP_PROJECTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSMNP_PROJECTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HRESULT CSMNP_PROJECTDlg::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;
}

HRESULT CSMNP_PROJECTDlg::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;
}

void CSMNP_PROJECTDlg::OnButtonExit()
{
	OnCancel();
}
void CSMNP_PROJECTDlg::OnBnClickedIdcButton()
{
	// TODO: Add your control notification handler code here
	CString szResulOID0;
	CString szResulOID1;
	CString szResulOID2;
	CString szResulOID3;
	CString szResulOID4;
	CString szResulOID5;
	CString szResulOID6;
	CString szResulOID7;

	DWORD dwError = 0;

	CString szTree;
	CGetInfo cGetInfo = new CGetInfo();
	if (!CheckInput())
	{
		MessageBox( _T("Input invalid!"), _T("ERROR"), MB_OK);
		return;
	}
	
	// Get All Value of system
	szTree = _T("1.3.6.1.2.1.1.1.0"); //sysDescr
	if (!GetDataFromAgent(m_szIPServer, m_szPortServer, m_szComunity, szTree, szResulOID0))
	{
		cGetInfo.m_szSysDescr.SetString(_T("ERROR"));
		dwError ++;
	}
	cGetInfo.m_szSysDescr = szResulOID0;

	szTree = _T("1.3.6.1.2.1.1.2.0"); //sysDescr
	if (!GetDataFromAgent(m_szIPServer, m_szPortServer, m_szComunity, szTree, szResulOID1))
	{
		cGetInfo.m_szSysObjectID.SetString(_T("ERROR"));
		dwError ++;
	}
	cGetInfo.m_szSysObjectID = szResulOID1;

	szTree = _T("1.3.6.1.2.1.1.3.0"); //sysDescr
	if (!GetDataFromAgent(m_szIPServer, m_szPortServer, m_szComunity, szTree, szResulOID2))
	{
		cGetInfo.m_szSysUpTime.SetString(_T("ERROR"));
		dwError ++;
	}
	cGetInfo.m_szSysUpTime = szResulOID2;

	szTree = _T("1.3.6.1.2.1.1.4.0"); //sysDescr
	if (!GetDataFromAgent(m_szIPServer, m_szPortServer, m_szComunity, szTree, szResulOID3))
	{
		cGetInfo.m_szSysContact.SetString(_T("ERROR"));
		dwError ++;
	}
	cGetInfo.m_szSysContact = szResulOID3;

	szTree = _T("1.3.6.1.2.1.1.5.0"); //sysDescr
	if (!GetDataFromAgent(m_szIPServer, m_szPortServer, m_szComunity, szTree, szResulOID4))
	{
		cGetInfo.m_szSysName.SetString(_T("ERROR"));
		dwError ++;
	}
	cGetInfo.m_szSysName = szResulOID4;

	szTree = _T("1.3.6.1.2.1.1.6.0"); //sysDescr
	if (!GetDataFromAgent(m_szIPServer, m_szPortServer, m_szComunity, szTree, szResulOID5))
	{
		cGetInfo.m_szSysLocation.SetString(_T("ERROR"));
		dwError ++;
	}
	cGetInfo.m_szSysLocation = szResulOID5;

	szTree = _T("1.3.6.1.2.1.1.7.0"); //sysDescr
	if (!GetDataFromAgent(m_szIPServer, m_szPortServer, m_szComunity, szTree, szResulOID6))
	{
		cGetInfo.m_szSysServices.SetString(_T("ERROR"));
		dwError ++;
	}
	cGetInfo.m_szSysServices = szResulOID6;

	szTree = _T("1.3.6.1.2.1.1.8.0"); //sysDescr
	if (!GetDataFromAgent(m_szIPServer, m_szPortServer, m_szComunity, szTree, szResulOID7))
	{
		cGetInfo.m_szSysORLastChange.SetString(_T("ERROR"));
		dwError ++;
	}
	cGetInfo.m_szSysORLastChange = szResulOID7;

	if (dwError == 8)
	{
		MessageBox("Can't get infomation from this agent!", "ERROR", MB_OK);
		return;
	}

	cGetInfo.DoModal();
}

BOOL CSMNP_PROJECTDlg::GetDataFromAgent(CString szServerIP, CString szPort, CString szComunity, CString szTree, CString& szResult)
{
	BOOL bRet = TRUE;
	int iPort = 0;
	int iOIDCount = 8;
	//CString szOIDArray[8];
	//CString szResultOID[8];

	iPort = _ttoi(szPort);
	SNMPManager::getManager()->startup();

	SNMPRemoteAgent ragent((LPCTSTR)szServerIP.GetString(), (LPCTSTR)szComunity.GetString(), iPort);

// 	szOIDArray[0] = _T("1.3.6.1.2.1.1.1.0"); //sysDescr
// 	szOIDArray[1] = _T("1.3.6.1.2.1.1.2.0"); //sysObjectID
// 	szOIDArray[2] = _T("1.3.6.1.2.1.1.3.0"); //sysUpTime
// 	szOIDArray[3] = _T("1.3.6.1.2.1.1.4.0"); //sysContact
// 	szOIDArray[4] = _T("1.3.6.1.2.1.1.5.0"); //sysName
// 	szOIDArray[5] = _T("1.3.6.1.2.1.1.6.0"); //sysLocation
// 	szOIDArray[6] = _T("1.3.6.1.2.1.1.7.0"); //sysServices
// 	szOIDArray[7] = _T("1.3.6.1.2.1.1.8.0"); //sysORLastChange

	SNMPObject * oids = new SNMPObject[1];
		
	oids->setOID((LPCTSTR)szTree.GetString());

	SNMPRemoteAgentGetRequest getReq(oids, 1);
	getReq.execute(&ragent);
	getReq.wait(10000);
	delete [] oids;		
	if(!getReq.succeeded()) {
		if(!getReq.timedOut()) {
		//	MessageBox(getReq.getErrorAsString().c_str(), _T("ERROR"), MB_OK);
			bRet = FALSE;
			goto exit_code;
		} else {
		//	MessageBox(_T("timeout"), _T("ERROR"), MB_OK);
			bRet = FALSE;
			goto exit_code;
		}
	} else {
		for(int i=0; i<getReq.getResultCount(); i++) {	
			//_tcscpy((char*)szResult.GetString(), getReq.getResult(i)->getDisplayInformation().c_str());
			szResult = getReq.getResult(i)->getDisplayInformation().c_str();
		}
	}
exit_code:
	return bRet;
}

void CAboutDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
void CSMNP_PROJECTDlg::OnCheckButton()
{
	// TODO: Add your control notification handler code here
	m_EditServerIP.SetWindowText("192.168.56.101");
	m_EditServerPort.SetWindowText("0");
	m_EditComunity.SetWindowText("public");
}

BOOL CSMNP_PROJECTDlg::CheckConnectToAgent()
{
	// use IP an Port to check connect to Agent
	BOOL bRet = FALSE;
	return bRet;
}

BOOL CSMNP_PROJECTDlg::CheckInput()
{
	BOOL bRet = TRUE;

	m_EditServerIP.GetWindowText(m_szIPServer);
	m_EditServerPort.GetWindowText(m_szPortServer);
	m_EditComunity.GetWindowText(m_szComunity);
	if (m_szPortServer == "" || m_szPortServer == "" || m_szComunity == "")
	{
		bRet = FALSE;
	}
	return bRet;
}
void CSMNP_PROJECTDlg::InitVar()
{
	m_szIPServer = "";
	m_szPortServer = "";
	m_bServerAvailable = FALSE;
}
