// CDlgFormat.cpp : implementation file
//

#include "pch.h"
#include "mfc_test.h"
#include "afxdialogex.h"
#include "CDlgFormat.h"


// CDlgFormat dialog

IMPLEMENT_DYNAMIC(CDlgFormat, CDialog)

CDlgFormat::CDlgFormat(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, m_width(0)
	, m_color(0)
{

}

CDlgFormat::~CDlgFormat()
{
}

void CDlgFormat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDB_WIDTH, m_width);
	DDX_Radio(pDX, IDC_RED, m_color);
	DDX_Control(pDX, IDB_WIDTH, m_width_control);
}


BEGIN_MESSAGE_MAP(CDlgFormat, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgFormat::OnBnClickedOk)
	ON_EN_CHANGE(IDB_WIDTH, &CDlgFormat::OnEnChangeWidth)
	ON_BN_CLICKED(IDC_BLUE, &CDlgFormat::OnBnClickedBlue)
	ON_BN_CLICKED(IDC_GREEN, &CDlgFormat::OnBnClickedGreen)
	ON_BN_CLICKED(IDC_RED, &CDlgFormat::OnBnClickedRed)
END_MESSAGE_MAP()


// CDlgFormat message handlers

void CDlgFormat::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	if (m_width > 3 || m_width < 1) 
		AfxMessageBox(L"Width should be an integer value between 1 and 3");
	else
		CDialog::OnOK();
}

void CDlgFormat::OnEnChangeWidth()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CDlgFormat::OnBnClickedBlue()
{
	// TODO: Add your control notification handler code here
	m_width_control.EnableWindow(0);
}

void CDlgFormat::OnBnClickedGreen()
{
	// TODO: Add your control notification handler code here
	m_width_control.EnableWindow(1);
}

void CDlgFormat::OnBnClickedRed()
{
	// TODO: Add your control notification handler code here
	m_width_control.EnableWindow(1);
}
