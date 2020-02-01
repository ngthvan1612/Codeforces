#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, a[201];
	cin >> n >> k;
	for (int i = 1; i <= 2 * n + 1; ++i)
		cin >> a[i];
	for (int i = 2; i <= 2 * n + 1; i += 2) {
		a[i]--;
		if (a[i - 1] < a[i] && a[i] > a[i + 1] && k > 0) { k--; continue; }
		else a[i]++;
	}
	for (int i = 1; i <= 2 * n + 1; ++i)
		cout << a[i] << ' ';
	return 0;
}
