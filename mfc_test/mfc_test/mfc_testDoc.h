
// mfc_testDoc.h : interface of the CmfctestDoc class
//


#pragma once


class CmfctestDoc : public CDocument
{
protected: // create from serialization only
	CmfctestDoc() noexcept;
	DECLARE_DYNCREATE(CmfctestDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CmfctestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
	int i;
	int j;
	COLORREF brush_clr;

public:
	int GetI();
	int GetJ();
	afx_msg void OnHi();
	afx_msg void OnDrawChange();
	COLORREF GetBrushClr();
	afx_msg void OnDrawRed();
	afx_msg void OnDrawGreen();
	afx_msg void OnDrawBlue();

protected:
	LOGPEN pen;
	LOGBRUSH brush;
public:
	LOGPEN& getPen();
	LOGBRUSH& getBrush();
	void updateclr();
	afx_msg void OnTakeovertheworld();
	afx_msg void OnDraw();
	afx_msg void OnFormat();
protected:
	int pen_clr;
public:
	int GetPenClr();
protected:
	int pen_width;
public:
	int GetPenWidth();
};
