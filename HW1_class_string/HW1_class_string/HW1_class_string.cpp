// HW1_class_string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ClString.h"

int main() {
	String hello("Hello World!");
	String s1(5, '.'), space(2), space1(space);
	std::cout << "Input/output\n";
	std::cout << hello << space << s1 << space1 << hello << std::endl;

	String s2(std::move(s1));
	std::cout << s1 << space << s2 << std::endl;

	std::cout << "Enter string:\n";
	std::cin >> s1;
	std::cout << s1 << std::endl;
	std::cout << s1.length() << std::endl;
	std::cout << "Operator[]\n";
	s1 = String("12345");
	s1[0] = s1[0] + 1;
	std::cout << s1 << std::endl;
	s2 = s1;
	std::cout << s2 << std::endl;
	s2 = std::move(s1);
	std::cout << s1 << space << s2 << std::endl;

	std::cout << "Enter string:\n";
	s1 = String("67890");
	std::cout << "Concatenation:\n";
	s2 += s1;
	std::cout << s2 << std::endl;
	
	std::cout << s1 + s2 << std::endl;
	std::cout << "Comparing:\n";
	s2 = s1;
	s1[s1.length() - 1] += 1;
	std::cout << s1 << "\n" << s2 << std::endl;
	std::cout << " <: " << (s1 < s2)  << std::endl;
	std::cout << "<=: " << (s1 <= s2) << std::endl;
	std::cout << "==: " << (s1 == s2) << std::endl;
	std::cout << " >: " << (s1 > s2)  << std::endl;
	std::cout << ">=: " << (s1 >= s2) << std::endl;
	std::cout << "!=: " << (s1 != s2) << std::endl;
	
	std::cout << "Substring:\n";
	std::cout << s1(1, 4) << std::endl;
	std::cout << s1(0, 4) << std::endl;
	std::cout << s1(1, 5) << std::endl;

	std::cout << "Convertion:\n";
	std::cout << (char*) s1 << std::endl;
}
