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
};
