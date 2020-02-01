#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if (k == 0 || k == n) { cout << 0 << ' ' << 0; return 0; }
	if (k <= n / 3) cout << 1 << ' ' << k * 2;
	else cout << 1 << ' ' << n - k;
	return 0;
}
