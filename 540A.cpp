#include <bits/stdc++.h>

using namespace std;

inline char lower(char c) { if ('A' <= c && c <= 'Z') c += 32; return c; }

int main() {
	int n, res = 0;
	string a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		int x = a[i] - '0', y = b[i] - '0';
		res += min(min(abs(y - x), x + 1 + 9 - y), 9 - x + 1 + y);
	}
	cout << res;
	return 0;
}
