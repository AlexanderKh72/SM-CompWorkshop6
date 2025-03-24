#pragma once
#include <iostream>

class Shape {  // abstract class
public:
    virtual double area() const = 0;  // fully virtual function
    virtual const char* name() const = 0; //  считается на лету, в разных наследниках по-разному
    int number() const { return id; }
    void print() { std::cout << name() << " No" << number() << "; area=" << area() << std::endl; }

protected:
    int id;
};

using comp_shape = bool(Shape*, Shape*);

bool comp_area(Shape* s1, Shape* s2);
void sort(Shape** arr, int n, comp_shape cmp);
