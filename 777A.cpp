#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x, a[3];
	cin >> n >> x;
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	n = (n - 1) % 6 + 1;
	for (int i = 1; i <= n; ++i) {
		if (i % 2) swap(a[0], a[1]);
		else swap(a[1], a[2]);
//		printf("%d: %d %d %d\n", i, a[0], a[1], a[2]);
	}
	cout << a[x];
	return 0;

