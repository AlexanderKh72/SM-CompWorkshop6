#pragma once
#include "afxdialogex.h"


// CSimulateDlg dialog

class CSimulateDlg : public CDialog
{
	DECLARE_DYNAMIC(CSimulateDlg)

public:
	CSimulateDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSimulateDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_method;
	CEdit m_ChengParameter_control;
	afx_msg void OnEnChangeChengparameter();
	int m_ChengParameter;
	double m_w1;
	double m_w2;
	double m_w3;
	double m_w4;
	double m_w5;
	int m_SampleSize;
	afx_msg void OnBnClickedCheng();
	afx_msg void OnBnClickedDichotomy();
	afx_msg void OnBnClickedOk();
	
	double m_h0_1;
	double m_h0_2;
	double m_h0_3;
	double m_h0_4;
	double m_h0_5;
};
