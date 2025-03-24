#pragma once
#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle(double aa, double bb) : a(aa), b(bb) { id = ++n; }
	const char* name() const override { return "Rectangle"; }
	double area() const override { return a * b; }

protected:
	double a;
	double b;
	static int n;
};

