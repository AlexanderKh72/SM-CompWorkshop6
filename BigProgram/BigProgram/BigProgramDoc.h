
// BigProgramDoc.h : interface of the CBigProgramDoc class
//


#pragma once
#include "Sample.h"
#include "Distribution.h"
#include "ChiSquare.h"
#include <random>

enum MODE { M_SAMPLE, M_PVALUE, M_ALPHAi };

class CBigProgramDoc : public CDocument
{
protected: // create from serialization only
	CBigProgramDoc() noexcept;
	DECLARE_DYNCREATE(CBigProgramDoc)

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
	virtual ~CBigProgramDoc();
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
private:
	Sample* sample;
	Distribution distr0;
	Distribution distr1;
	ChiSquare chisq;
public:
	Sample* getSample();
	void setSample(Sample* new_sample);
	afx_msg void OnSimulate();
private:
	int method;
	int cheng_parameter;
	double* weights;
	int sample_size;
	int nstates;
public:
	int get_method();
	int get_cheng_parameter();
	double* get_weights();
	int get_sample_size();
	int get_nstates();
private:
	std::mt19937 gen;
public:
	afx_msg void OnSimulateQuicksimulate();
	ChiSquare& get_chisq();
	afx_msg void OnPvalue();
	afx_msg void OnPQuicksimulate();
	afx_msg void OnTypeierror();
	afx_msg void OnTypeierrorQuicksimulate();
private:
	double* weightsH0;
private:
	MODE mode;
	double* pvalue;
	int pvalue_sample_size;

	int* sample_size_array;
	int alphaI_size;
	double* alphaI;
	double alpha;

private:
	int sample_size_step;
public:
	MODE get_mode();
	const double* get_pvalue();
	int get_pvalue_sample_size();
	const int* get_sample_size_array();
	int get_alphaI_size();
	const double* get_alphaI();
	double get_alpha();
};
