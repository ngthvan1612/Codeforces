#include <bits/stdc++.h>

using namespace std;

inline char lower(char c) { if ('A' <= c && c <= 'Z') c += 32; return c; }

int main() {
	const string vowel = "aoyeui";
	string s, res = "";
	cin >> s;
	int n = int(s.length());
	for (int i = 0; i < n; ++i) {
		bool testok = 1;
		for (char c : vowel)
			if (c == lower(s[i]))
				testok = 0;
		if (testok) res = res + "." + lower(s[i]);
	}
	cout << res;
	return 0;
}
