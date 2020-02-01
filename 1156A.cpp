#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[101], res = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n - 1; ++i) {
		if ((a[i] == 2 && a[i + 1] == 3) || (a[i] == 3 && a[i + 1] == 2)) {
			cout << "Infinite";
			return 0;
		}
		if (a[i] == 1 && a[i + 1] == 2) res += 3;
		if (a[i] == 1 && a[i + 1] == 3) res += 4;
		if (a[i] == 2 && a[i + 1] == 1) res += 3;
		if (a[i] == 3 && a[i + 1] == 1) res += 4;
		if (i <= n - 2 && a[i] == 3 && a[i + 1] == 1 && a[i + 2] == 2) res--;
	}
	cout << "Finite\n" << res;
	return 0;
}
