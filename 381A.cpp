#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[1000], s = 0, d = 0, tmp;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0, j = n - 1, who = 1; i <= j; who ^= 1) {
		if (a[i] > a[j]) { tmp = a[i]; i++; }
		else { tmp = a[j]; --j; }
		if (who) s += tmp;
		else d += tmp;
	}
	cout << s << ' ' << d;
	return 0;
}

