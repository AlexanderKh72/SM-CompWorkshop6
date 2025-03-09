#include "ClString.h"

String::String(int nstr, char c) : n(nstr), str(nullptr) {
	str = new char[n + 1];
	for (int i{ 0 }; i < n; ++i) str[i] = c;
	str[n] = '\0';
}

void String::swap(String& other) noexcept {
	std::swap(n, other.n);
	std::swap(str, other.str);
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

std::ostream& operator<<(std::ostream& out, const String& S)
{
	if (S.str) out << S.str;
	return out;
}
