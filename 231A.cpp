#include <bits/stdc++.h>

using namespace std;

inline char lower(char c) { if ('A' <= c && c <= 'Z') c += 32; return c; }

int main() {
	int n, a, b, c, res = 0;
	for (cin >> n; n--;) {
		cin >> a >> b >> c;
		if (a + b + c >= 2) res++;
	}
	cout << res;
	return 0;
}
