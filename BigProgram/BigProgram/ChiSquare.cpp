#include "ChiSquare.h"
#include "PROBDIST.H"

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
