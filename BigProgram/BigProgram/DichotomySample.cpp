#include "pch.h"
#include "DichotomySample.h"

void DichotomySample::simulate(const Distribution& distr, int sz, std::mt19937& gen) {
	int n = distr.get_nstates();
	double* s = new double[n];

	double summ{ 0 };
	for (int i{ 0 }; i < n; ++i) {
		summ += distr.get_p(i);
		s[i] = summ;
	}

	std::uniform_real_distribution<> rnd(0, 1);
	delete[] sample;
	sample = new int[n];
	nstates = n;
	for (int i = 0; i < nstates; sample[i++] = 0);

	for (int m = 0; m < sz; ++m) {
		double alpha = rnd(gen);
		int i{ 0 }, j{ n - 1 }, k;
		while (i < j) {
			k = (i + j) / 2;
			if (alpha < s[k])
				j = k;
			else
				i = k + 1;
		}
		++sample[i];
	}

	delete[] s;
}
