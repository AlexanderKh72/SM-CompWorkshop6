#pragma once
#include "afxdialogex.h"


// CPValueDlg dialog

class CPValueDlg : public CDialog
{
	DECLARE_DYNAMIC(CPValueDlg)

public:
	CPValueDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPValueDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_pv_ss;
	afx_msg void OnBnClickedOk();
};
