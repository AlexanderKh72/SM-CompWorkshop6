
// BigProgramView.cpp : implementation of the CBigProgramView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "BigProgram.h"
#endif

#include "BigProgramDoc.h"
#include "BigProgramView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBigProgramView

IMPLEMENT_DYNCREATE(CBigProgramView, CView)

BEGIN_MESSAGE_MAP(CBigProgramView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBigProgramView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CBigProgramView construction/destruction

CBigProgramView::CBigProgramView() noexcept
{
	// TODO: add construction code here

}

CBigProgramView::~CBigProgramView()
{
}

BOOL CBigProgramView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CBigProgramView drawing

void CBigProgramView::OnDraw(CDC* pDC)
{
	CBigProgramDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect rc;
	GetClientRect(&rc);
	int W = rc.Width(), H = rc.Height();
	switch (pDoc->get_mode()) {
		case M_SAMPLE:
			if (!(pDoc->getSample()))
				return;
			pDoc->get_chisq().histogram(pDC, W, H);
			break;
		case M_PVALUE:
		{
			CPen* pOldPen = (CPen*)pDC->SelectStockObject(BLACK_PEN);
			int plevel_distr[20] = {};
			for (int i{ 0 }; i < pDoc->get_pvalue_sample_size(); ++i) {
				if (int(pDoc->get_pvalue()[i] * 20) == 20) {
					TRACE("\n\n!!!---M_PVALUE == 1---!!!\n\n");
					++plevel_distr[19];
				}
				else
					++plevel_distr[int(pDoc->get_pvalue()[i] * 20)];
			}
			int x0 = W / 22, y0 = 14 * H / 15;
			int dx = W / 22;
			double dy = (13. * H) / (15 * pDoc->get_pvalue_sample_size());
			double f = 0;
			pDC->MoveTo(x0, y0);
			pDC->LineTo(x0, H / 15);
			pDC->MoveTo(x0, y0);
			pDC->LineTo(21 * W / 22, y0);
			pDC->MoveTo(x0, y0);
			CString str;
			CPen pen;
			for (int i = 1, x = x0 + dx; i <= 20; ++i, x += dx) {
				str.Format(L"%.2f", double(i) / 20);
				pDC->TextOut(x, y0 + 2, str);
				f += plevel_distr[i - 1];
				pDC->LineTo(x, int(y0 - dy * f));
			}
			pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
			pDC->SelectObject(pen);

			pDC->MoveTo(x0, y0);
			pDC->LineTo(x0 + 20 * dx, int(y0 - dy * pDoc->get_pvalue_sample_size()));

			pDC->SelectObject(pOldPen);
		}

			break;
		case M_ALPHAi:
		{
			int x0 = W / 22, y0 = 14 * H / 15;
			W = W / 22 * 20; H = H * 13 / 15;
			H = H / (2* pDoc->get_alpha());
			int dx = W / pDoc->get_alphaI_size();

			CPen pen;
			pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
			CPen* pOldPen = (CPen*)pDC->SelectObject(&pen);
			pDC->MoveTo(x0, int(y0 - pDoc->get_alpha() * H));
			pDC->LineTo(x0 + W, int(y0 - pDoc->get_alpha() * H));

			CString str;
			pDC->SetTextAlign(TA_TOP | TA_RIGHT);
			pen.DeleteObject();

			pDC->SelectStockObject(BLACK_PEN);
			pDC->MoveTo(x0, y0);
			pDC->LineTo(x0, y0-H);
			pDC->MoveTo(x0, y0);
			pDC->LineTo(x0+W, y0);
			str.Format(L"%.3f", 2* pDoc->get_alpha());
			pDC->TextOut(x0 - 2, y0 - 2*pDoc->get_alpha() * H, str);
			str.Format(L"%.3f", pDoc->get_alpha());
			pDC->TextOut(x0 - 2, int(y0 - pDoc->get_alpha() * H), str);
			
			pDC->SetTextAlign(TA_TOP | TA_LEFT);

			int x = x0 + dx / 2;
			pDC->MoveTo(x, int(y0 - pDoc->get_alphaI()[0] * H));
			str.Format(L"%d", pDoc->get_sample_size_array()[0]);
			pDC->TextOut(x, y0 + 2, str);
			TRACE("\n\n");
			x += dx;
			
			for (int i = 1; i < pDoc->get_alphaI_size(); ++i, x += dx) {
				TRACE("%d: %d\t%f\n", i, pDoc->get_sample_size_array()[i], pDoc->get_alphaI()[i]);
				pDC->LineTo(x, int(y0 - pDoc->get_alphaI()[i] * H));
				str.Format(L"%d", pDoc->get_sample_size_array()[i]);
				pDC->TextOut(x, y0 + 2, str);
			}
			TRACE("\n\n");

			pDC->SelectObject(pOldPen);
		}
			break;
	}
}


// CBigProgramView printing


void CBigProgramView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBigProgramView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBigProgramView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBigProgramView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CBigProgramView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBigProgramView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBigProgramView diagnostics

#ifdef _DEBUG
void CBigProgramView::AssertValid() const
{
	CView::AssertValid();
}

void CBigProgramView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBigProgramDoc* CBigProgramView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBigProgramDoc)));
	return (CBigProgramDoc*)m_pDocument;
}
#endif //_DEBUG


// CBigProgramView message handlers
