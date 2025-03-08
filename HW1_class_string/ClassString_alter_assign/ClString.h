#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>

class String {
private:
	char* str;
	int n;
	int IsEqual(const String& S) const { return strcmp(str, S.str); }
	int IsLessThan(const String& S) const { return (strcmp(str, S.str) <= 0); }

public:
	String() : str(nullptr), n(0) {}
	explicit String(int nstr, char c = ' ');
	void swap(String& other) noexcept;
	String(const char* s);
	String(const String& S);
	String(String&& S) noexcept : String() { this->swap(S); }
	~String() { delete[] str; }
	String& operator=(String S) { this->swap(S); return (*this); }
	char  operator[](int index) const { return str[index]; }
	char& operator[](int index) { return str[index]; }
	friend std::ostream& operator<<(std::ostream& out, const String& S);

	int length() const { return n; }
};