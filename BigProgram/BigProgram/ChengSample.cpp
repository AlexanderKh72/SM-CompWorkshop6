#include "pch.h"
#include "ChengSample.h"
#include <random>

void ChengSample::simulate(const Distribution& distr, int sz, std::mt19937& gen) {
	int n = distr.get_nstates();
	double* s = new double[n];
	int* r = new int[m];

	double summ{ 0 };
	for (int i{ 0 }; i < n; ++i) {
		summ += distr.get_p(i);
		s[i] = summ;
	}
	for (int i{ 0 }, j{ 0 }; i < n;) {
		if (m * s[i] >= j) {
			if (j < m)
				r[j] = i;
			++j;
		}
		else {
			++i;
		}
	}

	std::uniform_real_distribution<> rnd(0, 1);
	delete[] sample;
	sample = new int[n];
	nstates = n;
	for (int i = 0; i < nstates; sample[i++] = 0);

	for (int j = 0; j < sz; ++j) {
		double alpha = rnd(gen);
		int i{ r[int(m * alpha)] };
		for (; alpha > s[i]; ++i);
		++sample[i];
	}

	delete[] s;
	delete[] r;
}
