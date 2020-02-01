#include <bits/stdc++.h>

using namespace std;

inline char lower(char c) { if ('A' <= c && c <= 'Z') c += 32; return c; }

int main() {
	int n, m;
	cin >> n >> m;
	if (n % 2 == 0 || m % 2 == 0) cout << m * n / 2;
	else cout << max(n * (m - 1) / 2 + n / 2, m * (n - 1) / 2 + m / 2);
	return 0;
}
