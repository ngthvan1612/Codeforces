#include <bits/stdc++.h>

using namespace std;

inline char lower(char c) { if ('A' <= c && c <= 'Z') c += 32; return c; }

int main() {
	int n, x = 0;
	string s;
	for (cin >> n; n--;) {
		cin >> s;
		sort(s.begin(), s.end());
		cerr << s << '\n';
		if (s[0] == '-') x--;
		else x++;
	}
	cout << x;
	return 0;
}
