#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>

const int BUFF_SZ = 100;

class String {
private:
	char* str;
	int n;
	int IsEqual(const String& S) const { return strcmp(str, S.str); }
	int IsLessThan(const String& S) const { return (strcmp(str, S.str) <= 0); }

public:
	String() : str(nullptr), n(0) {}
	explicit String(int nstr, char c = ' ');
	String(const char* s);
	String(const String& S);
	String(String&& S);
	~String() { delete[] str; }
	String& operator=(const String& S);
	String& operator=(String&& S) noexcept;
	String& operator+=(const String& S);
	String operator()(int i, int j); //substring
	operator char* ();
	friend bool operator==(const String& s1, const String& s2) { return (s1.IsEqual(s2) == 0); }
	friend bool operator<=(const String& s1, const String& s2) { return (s1.IsLessThan(s2)); }
	friend bool operator!=(const String& s1, const String& s2) { return !(s1 == s2); }
	friend bool operator< (const String& s1, const String& s2) { return (s1 <= s2) && (s1 != s2); }
	friend bool operator> (const String& s1, const String& s2) { return !(s1 <= s2); }
	friend bool operator>=(const String& s1, const String& s2) { return !(s1 < s2); }
	friend String operator+ (const String& s1, const String& s2);
	friend std::ostream& operator<<(std::ostream& out, const String& S);
	friend std::istream& operator>>(std::istream& in, String& S);

	char  operator[](int index) const { return str[index]; }
	char& operator[](int index) { return str[index]; }

	int length() const { return n; }
};