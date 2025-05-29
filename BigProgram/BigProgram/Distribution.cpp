#include "pch.h"
#include "Distribution.h"

Distribution::Distribution(const double* weights, int n) : nstates(n), probs(nullptr) {
	probs = new double[nstates];
	double s = 0;
	for (int i = 0; i < n; s += weights[i++]);
	for (int i = 0; i < nstates; ++i) {
		probs[i] = weights[i] / s;
	}
}

void Distribution::set(const double* weights, int n) {
	delete[] probs;
	nstates = n;
	probs = new double[nstates];
	double s = 0;
	for (int i = 0; i < n; s += weights[i++]);
	for (int i = 0; i < nstates; ++i) {
		probs[i] = weights[i] / s;
	}
}
