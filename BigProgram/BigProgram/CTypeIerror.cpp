// CTypeIerror.cpp : implementation file
//

#include "pch.h"
#include "BigProgram.h"
#include "afxdialogex.h"
#include "CTypeIerror.h"


// CTypeIerror dialog

IMPLEMENT_DYNAMIC(CTypeIerrorDlg, CDialog)

CTypeIerrorDlg::CTypeIerrorDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG3, pParent)
	, m_method(0)
	, m_ChengParameter(0)
	, m_w1(0)
	, m_w2(0)
	, m_w3(0)
	, m_w4(0)
	, m_w5(0)
	, m_alpha(0)
	, m_ss_step(0)
	, m_nsteps(0)
{

}

CTypeIerrorDlg::~CTypeIerrorDlg()
{
}

void CTypeIerrorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_Cheng, m_method);
	DDX_Text(pDX, IDC_ChengParameter, m_ChengParameter);
	DDX_Text(pDX, IDC_H0_1, m_w1);
	DDX_Text(pDX, IDC_H0_2, m_w2);
	DDX_Text(pDX, IDC_H0_3, m_w3);
	DDX_Text(pDX, IDC_H0_4, m_w4);
	DDX_Text(pDX, IDC_H0_5, m_w5);
	DDX_Text(pDX, IDC_ALPHA, m_alpha);
	DDX_Text(pDX, IDC_SS_STEP, m_ss_step);
	DDX_Text(pDX, IDC_NSTEPS, m_nsteps);
}


BEGIN_MESSAGE_MAP(CTypeIerrorDlg, CDialog)
	ON_BN_CLICKED(IDC_Cheng, &CTypeIerrorDlg::OnBnClickedCheng)
	ON_EN_CHANGE(IDC_ChengParameter, &CTypeIerrorDlg::OnEnChangeChengparameter)
	ON_BN_CLICKED(IDOK, &CTypeIerrorDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTypeIerror message handlers

void CTypeIerrorDlg::OnBnClickedCheng()
{
	// TODO: Add your control notification handler code here
}

void CTypeIerrorDlg::OnEnChangeChengparameter()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CTypeIerrorDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	if (m_method == 0 && m_ChengParameter <= 0)
		AfxMessageBox(L"Parameter of Cheng methd (m) should be positive integer!");
	else if (m_w1 < 0 || m_w2 < 0 || m_w3 < 0 || m_w4 < 0 || m_w5 < 0)
		AfxMessageBox(L"Weights in distribution should be non-negative real values!");
	else if (m_w1 == 0 && m_w2 == 0 && m_w3 == 0 && m_w4 == 0 && m_w5 == 0)
		AfxMessageBox(L"At least one weight should be positive!");
	else if (m_alpha < 0 || m_alpha > 1)
		AfxMessageBox(L"Significance level must be between 0 and 1!");
	else if (m_ss_step < 0 || m_nsteps <= 0)
		AfxMessageBox(L"Number of steps and step size should be positive!");
	else {
		if (m_method == 1 && m_ChengParameter <= 0) {
			m_ChengParameter = 1;
			UpdateData(0);
		}
		CDialog::OnOK();
	}
}
