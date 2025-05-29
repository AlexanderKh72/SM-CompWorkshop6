#pragma once
#include "afxdialogex.h"


// CTypeIerror dialog

class CTypeIerrorDlg : public CDialog
{
	DECLARE_DYNAMIC(CTypeIerrorDlg)

public:
	CTypeIerrorDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTypeIerrorDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheng();
	int m_method;
	afx_msg void OnEnChangeChengparameter();
	int m_ChengParameter;
	double m_w1;
	double m_w2;
	double m_w3;
	double m_w4;
	double m_w5;
	double m_alpha;
	afx_msg void OnBnClickedOk();
	int m_ss_step;
	int m_nsteps;
};
