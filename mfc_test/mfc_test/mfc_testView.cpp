
// mfc_testView.cpp : implementation of the CmfctestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "mfc_test.h"
#endif

#include "mfc_testDoc.h"
#include "mfc_testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfctestView

IMPLEMENT_DYNCREATE(CmfctestView, CView)

BEGIN_MESSAGE_MAP(CmfctestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmfctestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
//	ON_COMMAND(ID_DRAW_RED, &CmfctestView::OnDrawRed)
END_MESSAGE_MAP()

// CmfctestView construction/destruction

CmfctestView::CmfctestView() noexcept
{
	// TODO: add construction code here

}

CmfctestView::~CmfctestView()
{
}

BOOL CmfctestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CmfctestView drawing

void CmfctestView::OnDraw(CDC* pDC)
{
	CmfctestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	CBrush brush;
	brush.CreateBrushIndirect(&(pDoc->getBrush()));
	CPen pen;
	pen.CreatePenIndirect(&(pDoc->getPen()));
	CBrush* pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	CPen* pOldPen = (CPen*)pDC->SelectObject(&pen);

	CRect rc;
	GetClientRect(&rc);

	pDC->Rectangle(rc.Width() / 4, rc.Height() / 4, 3 * rc.Width() / 4, 3 * rc.Height() / 4);

	POINT points[5];
	points[0].x = rc.Width() / 8; points[0].y = rc.Height() / 8;
	points[1].x = 7*rc.Width() / 8; points[1].y = rc.Height() / 8;
	points[2].x = 7*rc.Width() / 8; points[2].y = 7*rc.Height() / 8;
	points[3].x = rc.Width() / 8; points[3].y = 7*rc.Height() / 8;
	points[4].x = rc.Width() / 8; points[4].y = rc.Height() / 8;
	pDC->Polyline(points, 5);

	CFont font;
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	lf.lfHeight = rc.Height() / 8;
	lf.lfWeight = 700;
	lf.lfItalic = true;
	font.CreateFontIndirect(&lf);
	CFont* def_font = pDC->SelectObject(&font);

	pDC->SetTextAlign(VTA_CENTER);
	pDC->TextOut(rc.Width() / 2, 7 * rc.Height() / 16, L"Statmod");
	
	// Restore the old pen to the device context
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(def_font);
	font.DeleteObject();
	brush.DeleteObject();
}


// CmfctestView printing


void CmfctestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CmfctestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CmfctestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CmfctestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CmfctestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CmfctestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CmfctestView diagnostics

#ifdef _DEBUG
void CmfctestView::AssertValid() const
{
	CView::AssertValid();
}

void CmfctestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmfctestDoc* CmfctestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmfctestDoc)));
	return (CmfctestDoc*)m_pDocument;
}
#endif //_DEBUG


// CmfctestView message handlers