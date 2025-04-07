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
}


BEGIN_MESSAGE_MAP(CDlgFormat, CDialog)
END_MESSAGE_MAP()


// CDlgFormat message handlers
