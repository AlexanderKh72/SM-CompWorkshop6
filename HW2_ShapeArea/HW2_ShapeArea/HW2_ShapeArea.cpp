// HW2_ShapeArea.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "R32M.H"

const int N = 7;

int main()
{
    Shape* arr[N];
    rninit(4399);
    for (int i = 0; i < N; ++i) {
        if (rnunif() < 0.5)
            arr[i] = new Circle(rnunif() * 10);
        else
            arr[i] = new Rectangle(rnunif() * 20, rnunif() * 20);
    }

    for (int i = 0; i < N; ++i)
        arr[i]->print();

    sort(arr, N, comp_area);
    std::cout << "\n";
    for (int i = 0; i < N; ++i)
        arr[i]->print();

    for (int i = 0; i < N; ++i)
        delete arr[i];
}
