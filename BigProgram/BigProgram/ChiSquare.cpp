#include "pch.h"
#include "ChiSquare.h"
#include "PROBDIST.H"
#include "BigProgramDoc.h"
#include "BigProgramView.h"

ChiSquare::ChiSquare(Sample* sample, Distribution& distr) : 
	emp_freq(nullptr), theor_freq(nullptr), t(0), pvalue(0), df(0), nstates(sample->getNstates()) {

	emp_freq = new int[nstates];
	theor_freq = new double[nstates];
	int size = sample->size();
	for (int i = 0; i < nstates; ++i) {
		emp_freq[i] = sample->at(i);
		theor_freq[i] = distr.get_p(i) * size;
	}
    calculate();
}

ChiSquare::~ChiSquare() {
	delete[] emp_freq;
	delete[] theor_freq;
}

void ChiSquare::set(Sample* sample, Distribution& distr) {
	nstates = sample->getNstates();
	delete[] emp_freq;
	delete[] theor_freq;
	emp_freq = new int[nstates];
	theor_freq = new double[nstates];
	int size = sample->size();
	for (int i = 0; i < nstates; ++i) {
		emp_freq[i] = sample->at(i);
		theor_freq[i] = distr.get_p(i) * size;
	}
    calculate();
}

void ChiSquare::calculate() {
    t = 0;
    df = 0;
    int cumul_n = 0;
    double cumul_np = 0;
    int* group_obs = new int[nstates];
    double* group_exp = new double[nstates];
    for (int i = 0; i < nstates;) {
        for (; (cumul_np < 5) && (i < nstates); ++i) {
            cumul_n += emp_freq[i];
            cumul_np += theor_freq[i];
        }
        if (cumul_np >= 5) {
            group_obs[df] = cumul_n;
            group_exp[df] = cumul_np;
        }
        else {
            --df;
            group_obs[df] += cumul_n;
            group_exp[df] += cumul_np;
        }
        cumul_n = 0;
        cumul_np = 0;
        ++df;
    }

    for (int i = 0; i < df; ++i) {
        double term = (group_obs[i] - group_exp[i]) * (group_obs[i] - group_exp[i]) / (group_exp[i]);
        t += term;
    }
    --df;
    delete[] group_obs;
    delete[] group_exp;
    
	pvalue = 1 - pChi(t, df);
}

void ChiSquare::histogram(CDC* pDC, int W, int H) const {
	TRACE("\n\n");
	for (int i = 0; i < nstates; ++i) {
		TRACE("%d: %d\n", i, emp_freq[i]);
	}
	TRACE("\n\n");

	CBrush brush;
	brush.CreateSolidBrush(RGB(0, 0, 200));
	CBrush* pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	CPen* pOldPen = (CPen*)pDC->SelectStockObject(BLACK_PEN);

	int x0 = W / 22, y0 = 14 * H / 15;

	pDC->MoveTo(x0, y0);
	pDC->LineTo(x0, H / 15);
	pDC->MoveTo(x0, y0);
	pDC->LineTo(21 * W / 22, y0);

	double min_v = emp_freq[0], max_v = emp_freq[0];
	for (int i = 0; i < nstates; ++i) {
		if (emp_freq[i] < min_v)
			min_v = emp_freq[i];
		if (emp_freq[i] > max_v)
			max_v = emp_freq[i];
		if (theor_freq[i] < min_v)
			min_v = theor_freq[i];
		if (theor_freq[i] > max_v)
			max_v = theor_freq[i];
	}

	int dx = (5 * W) / (22 * nstates);
	double dy = double(13 * H) / (max_v * 15);

	for (int i = 0, x = x0 + dx; i < nstates; ++i, x += 4 * dx) {
		pDC->Rectangle(x, y0, x + 3 * dx, int(y0 - dy * emp_freq[i]));
	}
	brush.DeleteObject();
	brush.CreateSolidBrush(RGB(255, 71, 202));
	pDC->SelectObject(&brush);
	CString str;
	pDC->SetTextAlign(TA_TOP | TA_LEFT);
	for (int i = 0, x = x0 + dx; i < nstates; ++i, x += 4 * dx) {
		pDC->Rectangle(x + dx, y0, x + 2 * dx, int(y0 - dy * theor_freq[i]));
		str.Format(L"%d", i);
		pDC->TextOut(x + dx, y0+2, str);
	}

	pDC->MoveTo(x0, int(y0 - dy * min_v));
	pDC->LineTo(x0 + 10, int(y0 - dy * min_v));
	pDC->MoveTo(x0, int(y0 - dy * max_v));
	pDC->LineTo(x0 + 10, int(y0 - dy * max_v));

	pDC->SetTextAlign(TA_TOP | TA_RIGHT);
	str.Format(L"%.1f", min_v);
	pDC->TextOut(x0 - 3, int(y0 - dy * min_v), str);
	str.Format(L"%.1f", max_v);
	pDC->TextOut(x0 - 3, int(y0 - dy * max_v), str);

	pDC->SetTextAlign(TA_TOP | TA_LEFT);
	str.Format(L"chisq: %f, df: %d, p-value: %f", t, df, pvalue);
	pDC->TextOut(0, 0, str);

	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
	brush.DeleteObject();
}
