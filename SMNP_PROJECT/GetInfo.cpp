// GetInfo.cpp : implementation file
//

#include "stdafx.h"
#include "CSNMP_PROJECTApp.h"
#include "GetInfo.h"


// CGetInfo dialog

IMPLEMENT_DYNCREATE(CGetInfo, CDHtmlDialog)

CGetInfo::CGetInfo(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CGetInfo::IDD, CGetInfo::IDH, pParent)
{

}

CGetInfo::~CGetInfo()
{
}

void CGetInfo::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_Control(pDX, DESCR_IDC_EDIT, m_EditSysDescr);
	DDX_Control(pDX, OBJECTID_IDC_EDIT, m_EditSysObjectID);
	DDX_Control(pDX, UPTIME_IDC_EDIT, m_EditSysUptime);
	DDX_Control(pDX, CONTACT_IDC_EDIT, m_EditContact);
	DDX_Control(pDX, NAME_IDC_EDIT, m_EditName);
	DDX_Control(pDX, LOCATION_IDC_EDIT, m_EditLocation);
	DDX_Control(pDX, SERVICES_IDC_EDIT, m_EditServices);
	DDX_Control(pDX, ORLASTCHANGE_IDC_EDIT, m_EditORLastchange);
}

BOOL CGetInfo::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(CGetInfo, CDHtmlDialog)
	ON_BN_CLICKED(GET_IDOK, &CGetInfo::OnBnClickedIdok)
	ON_BN_CLICKED(GET_IDCANCEL, &CGetInfo::OnBnClickedIdcancel)
END_MESSAGE_MAP()

BEGIN_DHTML_EVENT_MAP(CGetInfo)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()



// CGetInfo message handlers

HRESULT CGetInfo::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;
}

HRESULT CGetInfo::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;
}

void CGetInfo::OnBnClickedIdok()
{
	// TODO: Add your control notification handler code here
	m_EditSysDescr.SetWindowText(m_szSysDescr);
	m_EditSysObjectID.SetWindowText(m_szSysObjectID);
	m_EditSysUptime.SetWindowText(m_szSysUpTime);
	m_EditContact.SetWindowText(m_szSysContact);
	m_EditName.SetWindowText(m_szSysName);
	m_EditLocation.SetWindowText(m_szSysLocation);
	m_EditServices.SetWindowText(m_szSysServices);
	m_EditORLastchange.SetWindowText(m_szSysORLastChange);
}

void CGetInfo::OnBnClickedIdcancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
