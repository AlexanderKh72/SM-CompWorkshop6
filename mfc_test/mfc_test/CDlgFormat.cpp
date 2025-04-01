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
{

}

CDlgFormat::~CDlgFormat()
{
}

void CDlgFormat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgFormat, CDialog)
END_MESSAGE_MAP()


// CDlgFormat message handlers
