// ClassString_alter_assign.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ClString.h"

int main()
{
    String s1("Hello World!");
    String s2;
    std::cout << s1 << " " << s2 << std::endl;
    s2 = s1;
    std::cout << s1 << " " << s2 << std::endl;
    s2 = std::move(s1);
    std::cout << s1 << " " << s2 << std::endl;

    return 0;
}
