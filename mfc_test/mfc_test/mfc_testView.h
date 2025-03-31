
// mfc_testView.h : interface of the CmfctestView class
//

#pragma once


class CmfctestView : public CView
{
protected: // create from serialization only
	CmfctestView() noexcept;
	DECLARE_DYNCREATE(CmfctestView)

// Attributes
public:
	CmfctestDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CmfctestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnDrawRed();
};

#ifndef _DEBUG  // debug version in mfc_testView.cpp
inline CmfctestDoc* CmfctestView::GetDocument() const
   { return reinterpret_cast<CmfctestDoc*>(m_pDocument); }
#endif

