// Examples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../BigProgram/DichotomySample.h"
#include "../BigProgram/ChengSample.h"
//#include "../BigProgram/ChiSquare.h"

int main() {
    double weights0[3] = { 1.0, 2.0, 3.0 };
    Distribution distr0(weights0, 3);
    std::cout << "Create distribution with weights:\n";
    for (int i = 0; i < 3; ++i)
        std::cout << i << ": " << weights0[i] << "; ";
    std::cout << "\nProbabilities:\n";
    for (int i = 0; i < 3; ++i)
        std::cout << i << ": " << distr0.get_p(i) << "; ";
}
