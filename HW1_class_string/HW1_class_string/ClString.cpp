#include "ClString.h"

String::String(int nstr, char c) : n(nstr), str(nullptr) {
	str = new char[n + 1];
	for (int i{ 0 }; i < n; ++i) str[i] = c;
	str[n] = '\0';
}


String::String(const char* s) : n(0), str(nullptr) {
	n = strlen(s);
	str = new char[n + 1];
	for (int i{ 0 }; i < n; ++i) str[i] = s[i];
	str[n] = '\0';
}

String::String(const String& S) : n(S.n), str(nullptr) {
	str = new char[n + 1];
	for (int i{ 0 }; i < n; ++i) str[i] = S[i];
	str[n] = '\0';
}

String::String(String&& S) : n(S.n), str(S.str) {
	S.n = 0;
	S.str = nullptr;
}

String& String::operator=(const String& S) {
	if (this == &S) return (*this);
	n = S.n;
	delete[] str;
	str = new char[n + 1];
	for (int i{ 0 }; i <= n; ++i) str[i] = S[i];

	return (*this);
}

String& String::operator=(String&& S) noexcept {
	if (this == &S) return (*this);
	n = S.n;
	str = S.str;
	S.n = 0;
	S.str = nullptr;
	return (*this);
}

String& String::operator+=(const String& S) {
	char* str_new = new char[n + S.n + 1];
	for (int i{ 0 }; i < n; ++i) str_new[i] = str[i];
	for (int i{ n }; i < n + S.n; ++i) str_new[i] = S[i - n];
	str_new[n + S.n] = '\0';
	delete[] str;
	str = str_new;
	n = n + S.n;
	return (*this);
}

String String::operator()(int i, int j)
{
	if (j > n) j = n;
	char* str_new = new char[j - i + 1];
	for (int k{ i }; k < j; ++k) str_new[k - i] = str[k];
	str_new[j - i] = '\0';
	return String(str_new);
}

String::operator char* () {
	char* res = new char[n + 1];
	for (int i{ 0 }; i < n; ++i) res[i] = str[i];
	res[n] = '\0';
	return res;
}

String operator+(const String& s1, const String& s2) {
	String res(s1);
	return (res += s2);
}

std::ostream& operator<<(std::ostream& out, const String& S)
{
	if (S.str) out << S.str;
	return out; 
}

std::istream& operator>>(std::istream& in, String& S) {
	char* buff = new char[BUFF_SZ];
	in >> buff;
	S.n = strlen(buff);
	delete[] S.str;
	S.str = new char[S.n + 1];
	for (int i{ 0 }; i < S.n; ++i) S[i] = buff[i];
	S[S.n] = '\0';
	return in;
}
