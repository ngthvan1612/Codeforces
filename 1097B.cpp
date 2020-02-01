#include <bits/stdc++.h>

using namespace std;

int n, a[16];

int canZero(int c, int deg) {
	if (c == n + 1) {
		if (deg == 0) return 1;
		return 0;
	}
	return canZero(c + 1, (deg + a[c]) % 360) | canZero(c + 1, (deg - a[c] + 360 * 5) % 360);
}

int main() {
	cin >> n;
	for (int i= 1; i <= n; ++i)
		cin >> a[i];
	if (canZero(1, 0)) cout << "YES";
	else cout << "NO";
	return 0;
}

