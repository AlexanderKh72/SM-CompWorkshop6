// CPValueDlg.cpp : implementation file
//

#include "pch.h"
#include "BigProgram.h"
#include "afxdialogex.h"
#include "CPValueDlg.h"


// CPValueDlg dialog

IMPLEMENT_DYNAMIC(CPValueDlg, CDialog)

CPValueDlg::CPValueDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, m_pv_ss(0)
{

}

CPValueDlg::~CPValueDlg()
{
}

void CPValueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PV_SS, m_pv_ss);
}


BEGIN_MESSAGE_MAP(CPValueDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CPValueDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CPValueDlg message handlers

void CPValueDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	if (m_pv_ss > 0)
		CDialog::OnOK();
	else
		AfxMessageBox(L"p-value sample size must be greater than 0!");
}
