
// mfc_testDoc.cpp : implementation of the CmfctestDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "mfc_test.h"
#endif

#include "mfc_testDoc.h"

#include <propkey.h>

#include "CDlgTakeover.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CmfctestDoc

IMPLEMENT_DYNCREATE(CmfctestDoc, CDocument)

BEGIN_MESSAGE_MAP(CmfctestDoc, CDocument)
	ON_COMMAND(ID_HI, &CmfctestDoc::OnHi)
	ON_COMMAND(ID_DRAW_CHANGE, &CmfctestDoc::OnDrawChange)
	ON_COMMAND(ID_DRAW_RED, &CmfctestDoc::OnDrawRed)
	ON_COMMAND(ID_DRAW_GREEN, &CmfctestDoc::OnDrawGreen)
	ON_COMMAND(ID_DRAW_BLUE, &CmfctestDoc::OnDrawBlue)
	ON_COMMAND(ID_TAKEOVERTHEWORLD, &CmfctestDoc::OnTakeovertheworld)
	ON_COMMAND(ID_DRAW, &CmfctestDoc::OnDraw)
END_MESSAGE_MAP()


// CmfctestDoc construction/destruction

CmfctestDoc::CmfctestDoc() noexcept
{
	// TODO: add one-time construction code here

}

CmfctestDoc::~CmfctestDoc()
{
}

BOOL CmfctestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	i = 200;
	j = 300;

	clr = RGB(0, 0, 0);

	pen.lopnColor = clr;
	pen.lopnWidth.x = 2;
	
	brush.lbStyle = BS_SOLID;
	brush.lbColor = clr;
	
	return TRUE;
}




// CmfctestDoc serialization

void CmfctestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CmfctestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CmfctestDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CmfctestDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CmfctestDoc diagnostics

#ifdef _DEBUG
void CmfctestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CmfctestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CmfctestDoc commands

int CmfctestDoc::GetI()
{
	// TODO: Add your implementation code here.
	return i;
}

int CmfctestDoc::GetJ()
{
	return j;
}

void CmfctestDoc::OnHi()
{
	// TODO: Add your command handler code here
	AfxMessageBox(L"Hi!");
}

void CmfctestDoc::OnDrawChange()
{
	// TODO: Add your command handler code here
	i = 300;
	UpdateAllViews(0);
}

COLORREF CmfctestDoc::GetClr()
{
	// TODO: Add your implementation code here.
	return clr;
}

void CmfctestDoc::OnDrawRed()
{
	clr = RGB(255, 0, 0);
	updateclr();
	UpdateAllViews(0);
}

void CmfctestDoc::OnDrawGreen()
{
	clr = RGB(0, 255, 0);
	updateclr();
	UpdateAllViews(0);
}

void CmfctestDoc::OnDrawBlue()
{
	clr = RGB(0, 0, 255);
	updateclr();
	UpdateAllViews(0);
}

LOGPEN& CmfctestDoc::getPen()
{
	// TODO: Add your implementation code here.
	// TODO: insert return statement here

	return pen;
}

LOGBRUSH& CmfctestDoc::getBrush()
{
	// TODO: Add your implementation code here.
	// TODO: insert return statement here

	return brush;
}

void CmfctestDoc::updateclr()
{
	// TODO: Add your implementation code here.
	pen.lopnColor = GetClr();
	brush.lbColor = GetClr();
}

void CmfctestDoc::OnTakeovertheworld()
{
	// TODO: Add your command handler code here
	CDlgTakeover d;
	d.DoModal();
}

void CmfctestDoc::OnDraw()
{
	CColorDialog dlg(RGB(0, 0, 0));
	dlg.DoModal();
}
