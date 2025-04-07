#pragma once
#include "afxdialogex.h"


// CDlgFormat dialog

class CDlgFormat : public CDialog
{
	DECLARE_DYNAMIC(CDlgFormat)

public:
	CDlgFormat(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgFormat();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_width;
	int m_color;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeWidth();
	CEdit m_width_control;
	afx_msg void OnBnClickedBlue();
	afx_msg void OnBnClickedGreen();
	afx_msg void OnBnClickedRed();
};
