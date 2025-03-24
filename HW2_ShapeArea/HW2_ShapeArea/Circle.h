#pragma once
#include "Shape.h"
#define M_PI 3.1415926535

class Circle : public Shape {
public:
	explicit Circle(double rr) : r(rr) { id = ++n; }
	const char* name() const override { return "Circle"; }
	double area() const override { return M_PI * r*r; }

protected:
	double r;
	static int n;
};

