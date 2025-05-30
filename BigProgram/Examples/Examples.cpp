// Examples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include "../BigProgram/DichotomySample.h"
#include "../BigProgram/ChengSample.h"
#include "../BigProgram/ChiSquare.h"

int main() {
    double weights1[3] = { 1.0, 2.0, 3.0 };
    Distribution distr1(weights1, 3);
    std::cout << "Create distribution P_1 with weights:\n";
    for (int i = 0; i < 3; ++i)
        std::cout << i << ": " << weights1[i] << ";\t";
    std::cout << "\nProbabilities:\n";
    for (int i = 0; i < distr1.getNstates(); ++i)
        std::cout << i << ": " << distr1.get_p(i) << ";\t";

    std::mt19937 gen(42);

    Sample* sample;
    sample = new DichotomySample;
    sample->simulate(distr1, 100, gen);
    std::cout << "\n\nSample of distribution P_1 (dichotomy simulation method):\n";
    for (int i = 0; i < sample->getNstates(); ++i)
        std::cout << i << ": " << sample->at(i) << ";\t";
    delete sample;

    sample = new ChengSample(4);
    sample->simulate(distr1, 100, gen);
    std::cout << "\n\nSample (1) of distribution P_1 (Cheng simulation method with m=4):\n";
    for (int i = 0; i < sample->getNstates(); ++i)
        std::cout << i << ": " << sample->at(i) << ";\t";

    double weights0[] = { 1,3,3 };
    Distribution distr0(weights0, 3);
    std::cout << "\n\nCreate distribution P_0 with weights:\n";
    for (int i = 0; i < 3; ++i)
        std::cout << i << ": " << weights0[i] << ";\t";
    std::cout << "\nProbabilities:\n";
    for (int i = 0; i < distr0.getNstates(); ++i)
        std::cout << i << ": " << distr0.get_p(i) << ";\t";

    std::cout << "\n\nApply chi-square criteria to Sample (1) and distribution P_0 (H_0 hypothesis):\n";
    ChiSquare chisq(sample, distr0);
    std::cout << "statistic: " << chisq.get_statistic() << "\t df: " << chisq.get_df() << "\t p-value: " << chisq.get_pvalue();

    delete sample;
}
