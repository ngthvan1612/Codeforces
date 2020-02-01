#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[101], imin = 0, imax = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	imin = imax = 1;
	for (int i = 2; i <= n; ++i) {
		if (a[imax] < a[i]) imax = i;
		if (a[imin] >= a[i]) imin = i;
	}
	if (imin < imax) cout << imax - 1 + n - imin - 1;
	else cout << imax - 1 + n - imin;
	return 0;
}

