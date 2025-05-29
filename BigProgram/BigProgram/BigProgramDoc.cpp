
// BigProgramDoc.cpp : implementation of the CBigProgramDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "BigProgram.h"
#endif

#include "BigProgramDoc.h"

#include <propkey.h>
#include "CSimulateDlg.h"
#include "CPValueDlg.h"
#include "CTypeIerror.h"
#include "ChengSample.h"
#include "DichotomySample.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CBigProgramDoc

IMPLEMENT_DYNCREATE(CBigProgramDoc, CDocument)

BEGIN_MESSAGE_MAP(CBigProgramDoc, CDocument)
	ON_COMMAND(ID_SIMULATE, &CBigProgramDoc::OnSimulate)
	ON_COMMAND(ID_SIMULATE_QUICKSIMULATE, &CBigProgramDoc::OnSimulateQuicksimulate)
	ON_COMMAND(ID_PVALUE, &CBigProgramDoc::OnPvalue)
	ON_COMMAND(ID_P_QUICKSIMULATE, &CBigProgramDoc::OnPQuicksimulate)
	ON_COMMAND(ID_TYPEIERROR, &CBigProgramDoc::OnTypeierror)
	ON_COMMAND(ID_TYPEIERROR_QUICKSIMULATE, &CBigProgramDoc::OnTypeierrorQuicksimulate)
END_MESSAGE_MAP()


// CBigProgramDoc construction/destruction

CBigProgramDoc::CBigProgramDoc() noexcept : cheng_parameter(4), method(0), 
	nstates(5), sample_size(100), weights(nullptr), weightsH0(nullptr), sample(nullptr), mode(M_SAMPLE),
	pvalue(nullptr), pvalue_sample_size(1000), alphaI_size(10), sample_size_array(nullptr), alphaI(nullptr), 
	alpha(0.05), sample_size_step(100) {
	// TODO: add one-time construction code here
	weights = new double[nstates];
	weightsH0 = new double[nstates];
	pvalue = new double[pvalue_sample_size];
	for (int i = 0; i < nstates; weightsH0[i] = 1, weights[i++] = 1);
	sample_size_array = new int[alphaI_size];
	alphaI = new double[alphaI_size];
	for (int n = 0, i = 0; i < alphaI_size; sample_size_array[i++] = (n += sample_size_step));
	distr1.set(weights, nstates);
	distr0.set(weightsH0, nstates);
}

CBigProgramDoc::~CBigProgramDoc()
{
	delete sample;
	delete[] weights;
	delete[] weightsH0;
	delete[] pvalue;
	delete[] alphaI;
	delete[] sample_size_array;
}

BOOL CBigProgramDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	gen = std::mt19937(4399);
	
	return TRUE;
}




// CBigProgramDoc serialization

void CBigProgramDoc::Serialize(CArchive& ar)
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
void CBigProgramDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CBigProgramDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CBigProgramDoc::SetSearchContent(const CString& value)
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

// CBigProgramDoc diagnostics

#ifdef _DEBUG
void CBigProgramDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBigProgramDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CBigProgramDoc commands

Sample* CBigProgramDoc::getSample() {
	// TODO: Add your implementation code here.
	return sample;
}

void CBigProgramDoc::setSample(Sample* new_sample)
{
	// TODO: Add your implementation code here.
	delete[] sample;
	sample = new_sample;
}

void CBigProgramDoc::OnSimulate()
{
	CSimulateDlg d;
	d.m_method = method;
	d.m_ChengParameter = cheng_parameter;
	d.m_w1 = weights[0];
	d.m_w2 = weights[1];
	d.m_w3 = weights[2];
	d.m_w4 = weights[3];
	d.m_w5 = weights[4];

	d.m_h0_1 = weightsH0[0];
	d.m_h0_2 = weightsH0[1];
	d.m_h0_3 = weightsH0[2];
	d.m_h0_4 = weightsH0[3];
	d.m_h0_5 = weightsH0[4];
	d.m_SampleSize = sample_size;
	if (d.DoModal() == IDOK) {
		method = d.m_method;
		cheng_parameter = d.m_ChengParameter;
		weights[0] = d.m_w1;
		weights[1] = d.m_w2;
		weights[2] = d.m_w3;
		weights[3] = d.m_w4;
		weights[4] = d.m_w5;

		weightsH0[0] = d.m_h0_1;
		weightsH0[1] = d.m_h0_2;
		weightsH0[2] = d.m_h0_3;
		weightsH0[3] = d.m_h0_4;
		weightsH0[4] = d.m_h0_5;
		sample_size = d.m_SampleSize;
		distr1.set(weights, nstates);
		distr0.set(weightsH0, nstates);
		OnSimulateQuicksimulate();
		//delete sample;
		//if (method == 0)
		//	sample = new ChengSample(cheng_parameter);
		//else
		//	sample = new DichotomySample;
		//distr1.set(weights, nstates);
		//distr0.set(weightsH0, nstates);
		//sample->simulate(distr1, sample_size, gen);
		//chisq.set(sample, distr0);
		//mode = M_SAMPLE;
		//UpdateAllViews(0);
	}
	// TODO: Add your command handler code here
}

int CBigProgramDoc::get_method()
{
	// TODO: Add your implementation code here.
	return method;
}

int CBigProgramDoc::get_cheng_parameter()
{
	// TODO: Add your implementation code here.
	return cheng_parameter;
}

double* CBigProgramDoc::get_weights()
{
	// TODO: Add your implementation code here.
	return weights;
}

int CBigProgramDoc::get_sample_size()
{
	// TODO: Add your implementation code here.
	return sample_size;
}

int CBigProgramDoc::get_nstates()
{
	// TODO: Add your implementation code here.
	return nstates;
}


/*
int CBigProgramDoc::get_method()
{
	// TODO: Add your implementation code here.
	return method;
}

int CBigProgramDoc::get_cheng_parameter()
{
	// TODO: Add your implementation code here.
	return cheng_parameter;
}

double* CBigProgramDoc::get_weights()
{
	// TODO: Add your implementation code here.
	return weights;
}

int CBigProgramDoc::get_sample_size()
{
	// TODO: Add your implementation code here.
	return sample_size;
}

int CBigProgramDoc::get_nstates()
{
	// TODO: Add your implementation code here.
	return nstates;
}

*/
void CBigProgramDoc::OnSimulateQuicksimulate()
{
	// TODO: Add your command handler code here
	//if (!sample) {
	//	AfxMessageBox(L"Simulation method or distribution parameters haven't been set!\nPlease, select \"Set parameters\" option.");
	//	return;
	//}
	delete sample;
	if (method == 0)
		sample = new ChengSample(cheng_parameter);
	else
		sample = new DichotomySample;
	//sample->simulate(distr1, sample_size, gen);
	//chisq.set(sample, distr0);
	//mode = SAMPLE;

	sample->simulate(distr1, sample_size, gen);
	chisq.set(sample, distr0);
	mode = M_SAMPLE;
	UpdateAllViews(0);
}

ChiSquare& CBigProgramDoc::get_chisq()
{
	// TODO: Add your implementation code here.
	// TODO: insert return statement here
	return chisq;
}

void CBigProgramDoc::OnPvalue()
{
	// TODO: Add your command handler code here
	CSimulateDlg d_param;
	CPValueDlg d_pvalue;

	d_param.m_method = method;
	d_param.m_ChengParameter = cheng_parameter;
	d_param.m_w1 = weights[0];
	d_param.m_w2 = weights[1];
	d_param.m_w3 = weights[2];
	d_param.m_w4 = weights[3];
	d_param.m_w5 = weights[4];

	d_param.m_h0_1 = weightsH0[0];
	d_param.m_h0_2 = weightsH0[1];
	d_param.m_h0_3 = weightsH0[2];
	d_param.m_h0_4 = weightsH0[3];
	d_param.m_h0_5 = weightsH0[4];
	d_param.m_SampleSize = sample_size;

	d_pvalue.m_pv_ss = pvalue_sample_size;
	if (d_param.DoModal() == IDOK && d_pvalue.DoModal() == IDOK) {
		method = d_param.m_method;
		cheng_parameter = d_param.m_ChengParameter;
		weights[0] = d_param.m_w1;
		weights[1] = d_param.m_w2;
		weights[2] = d_param.m_w3;
		weights[3] = d_param.m_w4;
		weights[4] = d_param.m_w5;

		weightsH0[0] = d_param.m_h0_1;
		weightsH0[1] = d_param.m_h0_2;
		weightsH0[2] = d_param.m_h0_3;
		weightsH0[3] = d_param.m_h0_4;
		weightsH0[4] = d_param.m_h0_5;
		sample_size = d_param.m_SampleSize;
		pvalue_sample_size = d_pvalue.m_pv_ss;
		delete[] pvalue;
		pvalue = new double[pvalue_sample_size];

		OnPQuicksimulate();
		//delete sample;
		//if (method == 0)
		//	sample = new ChengSample(cheng_parameter);
		//else
		//	sample = new DichotomySample;
		//distr1.set(weights, nstates);
		//distr0.set(weightsH0, nstates);

		//
		//for (int i = 0; i < pvalue_sample_size; ++i) {
		//	sample->simulate(distr1, sample_size, gen);
		//	chisq.set(sample, distr0);
		//	pvalue[i] = chisq.get_pvalue();
		//}
		//mode = M_PVALUE;
		//UpdateAllViews(0);
	}
}

void CBigProgramDoc::OnPQuicksimulate()
{
	// TODO: Add your command handler code here
	//if(!sample) {
	//	AfxMessageBox(L"Simulation method or distribution parameters haven't been set!\nPlease, select \"Set parameters\" option.");
	//	return;
	//}
	delete sample;
	if (method == 0)
		sample = new ChengSample(cheng_parameter);
	else
		sample = new DichotomySample;
	distr1.set(weights, nstates);
	distr0.set(weightsH0, nstates);
	for (int i = 0; i < pvalue_sample_size; ++i) {
		sample->simulate(distr1, sample_size, gen);
		chisq.set(sample, distr0);
		pvalue[i] = chisq.get_pvalue();
	}
	mode = M_PVALUE;
	UpdateAllViews(0);
}

void CBigProgramDoc::OnTypeierror()
{
	// TODO: Add your command handler code here
	CTypeIerrorDlg d;
	d.m_method = method;
	d.m_ChengParameter = cheng_parameter;
	d.m_w1 = weightsH0[0];
	d.m_w2 = weightsH0[1];
	d.m_w3 = weightsH0[2];
	d.m_w4 = weightsH0[3];
	d.m_w5 = weightsH0[4];
	d.m_alpha = alpha;
	d.m_ss_step = sample_size_step;
	d.m_nsteps = alphaI_size;

	if (d.DoModal() == IDOK) {
		method = d.m_method;
		cheng_parameter = d.m_ChengParameter;
		weightsH0[0] = d.m_w1;
		weightsH0[1] = d.m_w2;
		weightsH0[2] = d.m_w3;
		weightsH0[3] = d.m_w4;
		weightsH0[4] = d.m_w5;
		alpha = d.m_alpha;
		sample_size_step = d.m_ss_step;
		alphaI_size = d.m_nsteps;

		distr0.set(weightsH0, nstates);
		delete[] sample_size_array;
		sample_size_array = new int[alphaI_size];
		for (int n = 0, i = 0; i < alphaI_size; sample_size_array[i++] = (n += sample_size_step));
		delete[] alphaI;
		alphaI = new double[alphaI_size];
		OnTypeierrorQuicksimulate();
		//delete sample;
		//if (method == 0)
		//	sample = new ChengSample(cheng_parameter);
		//else
		//	sample = new DichotomySample;
		//
		//for (int j = 0; j < alphaI_size; ++j) {
		//	int n = sample_size_array[j];
		//	alphaI[j] = 0;
		//	for (int i = 0; i < pvalue_sample_size; ++i) {
		//		sample->simulate(distr0, n, gen);
		//		chisq.set(sample, distr0);
		//		if (chisq.get_pvalue() < alpha) {
		//			alphaI[j] += 1;
		//		}
		//	}
		//	alphaI[j] /= n;
		//}
		//mode = M_ALPHAi;
		//UpdateAllViews(0);
	}
}

void CBigProgramDoc::OnTypeierrorQuicksimulate()
{
	delete sample;
	if (method == 0)
		sample = new ChengSample(cheng_parameter);
	else
		sample = new DichotomySample;
	// distr0.set(weightsH0, nstates);
	for (int j = 0; j < alphaI_size; ++j) {
		int n = sample_size_array[j];
		alphaI[j] = 0;
		for (int i = 0; i < pvalue_sample_size; ++i) {
			sample->simulate(distr0, n, gen);
			chisq.set(sample, distr0);
			if (chisq.get_pvalue() < alpha) {
				alphaI[j] += 1;
			}
		}
		alphaI[j] /= pvalue_sample_size;
	}
	mode = M_ALPHAi;
	UpdateAllViews(0);
}

MODE CBigProgramDoc::get_mode()
{
	// TODO: Add your implementation code here.
	return mode;
}

const double* CBigProgramDoc::get_pvalue()
{
	// TODO: Add your implementation code here.
	return pvalue;
}

int CBigProgramDoc::get_pvalue_sample_size()
{
	// TODO: Add your implementation code here.
	return pvalue_sample_size;
}

const int* CBigProgramDoc::get_sample_size_array()
{
	// TODO: Add your implementation code here.
	return sample_size_array;
}

int CBigProgramDoc::get_alphaI_size()
{
	// TODO: Add your implementation code here.
	return alphaI_size;
}

const double* CBigProgramDoc::get_alphaI()
{
	// TODO: Add your implementation code here.
	return alphaI;
}

double CBigProgramDoc::get_alpha()
{
	// TODO: Add your implementation code here.
	return alpha;
}
