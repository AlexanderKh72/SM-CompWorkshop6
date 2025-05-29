// CSimulateDlg.cpp : implementation file
//

#include "pch.h"
#include "BigProgram.h"
#include "afxdialogex.h"
#include "CSimulateDlg.h"


// CSimulateDlg dialog

IMPLEMENT_DYNAMIC(CSimulateDlg, CDialog)

CSimulateDlg::CSimulateDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_method(0)
	, m_ChengParameter(0)
	, m_w1(0)
	, m_w2(0)
	, m_w3(0)
	, m_w4(0)
	, m_w5(0)
	, m_SampleSize(0)
	, m_h0_1(0)
	, m_h0_2(0)
	, m_h0_3(0)
	, m_h0_4(0)
	, m_h0_5(0)
{

}

CSimulateDlg::~CSimulateDlg()
{
}

void CSimulateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_Cheng, m_method);
	DDX_Control(pDX, IDC_ChengParameter, m_ChengParameter_control);
	DDX_Text(pDX, IDC_ChengParameter, m_ChengParameter);
	DDX_Text(pDX, IDC_P1, m_w1);
	DDX_Text(pDX, IDC_P2, m_w2);
	DDX_Text(pDX, IDC_P3, m_w3);
	DDX_Text(pDX, IDC_P4, m_w4);
	DDX_Text(pDX, IDC_P5, m_w5);
	DDX_Text(pDX, IDC_SampleSize, m_SampleSize);
	DDX_Text(pDX, IDC_H0_1, m_h0_1);
	DDX_Text(pDX, IDC_H0_2, m_h0_2);
	DDX_Text(pDX, IDC_H0_3, m_h0_3);
	DDX_Text(pDX, IDC_H0_4, m_h0_4);
	DDX_Text(pDX, IDC_H0_5, m_h0_5);
}


BEGIN_MESSAGE_MAP(CSimulateDlg, CDialog)
	ON_EN_CHANGE(IDC_ChengParameter, &CSimulateDlg::OnEnChangeChengparameter)
	ON_BN_CLICKED(IDC_Cheng, &CSimulateDlg::OnBnClickedCheng)
	ON_BN_CLICKED(IDC_Dichotomy, &CSimulateDlg::OnBnClickedDichotomy)
	ON_BN_CLICKED(IDOK, &CSimulateDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSimulateDlg message handlers

void CSimulateDlg::OnEnChangeChengparameter()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CSimulateDlg::OnBnClickedCheng()
{
	// TODO: Add your control notification handler code here
	//m_ChengParameter_control.EnableWindow(1);
}

void CSimulateDlg::OnBnClickedDichotomy()
{
	// TODO: Add your control notification handler code here
	//m_ChengParameter_control.EnableWindow(0);
}

void CSimulateDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	if (m_method == 0 && m_ChengParameter <= 0)
		AfxMessageBox(L"Parameter of Cheng methd (m) should be positive integer!");
	else if (m_w1 < 0 || m_w2 < 0 || m_w3 < 0 || m_w4 < 0 || m_w5 < 0)
		AfxMessageBox(L"Weights in distribution should be non-negative real values!");
	else if (m_w1 == 0 && m_w2 == 0 && m_w3 == 0 && m_w4 == 0 && m_w5 == 0)
		AfxMessageBox(L"At least one weight should be positive!");
	else if (m_h0_1 < 0 || m_h0_2 < 0 || m_h0_3 < 0 || m_h0_4 < 0 || m_h0_5 < 0)
		AfxMessageBox(L"Weights in distribution should be non-negative real values!");
	else if (m_h0_1 == 0 && m_h0_2 == 0 && m_h0_3 == 0 && m_h0_4 == 0 && m_h0_5 == 0)
		AfxMessageBox(L"At least one weight should be positive!");
	else if (m_SampleSize <= 0)
		AfxMessageBox(L"Sample size should be positive integer!");
	else {
		if (m_method == 1 && m_ChengParameter <= 0) {
			m_ChengParameter = 1;
			UpdateData(0);
		}
		CDialog::OnOK();
	}
}
