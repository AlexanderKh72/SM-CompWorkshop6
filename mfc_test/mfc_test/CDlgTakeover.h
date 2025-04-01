#pragma once
#include "afxdialogex.h"


// CDlgTakeover dialog

class CDlgTakeover : public CDialog
{
	DECLARE_DYNAMIC(CDlgTakeover)

public:
	CDlgTakeover(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgTakeover();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
