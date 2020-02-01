#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[1001], sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i], sum += a[i];
	for (int s = 1; s < (1 << n) - 1; ++s) {
		int s1 = 0;
		for (int j = 0; j < n; ++j)
			if ((1 << j) & s)
				s1 += a[j];
		if (s1 * 2 != sum) {
			cout << __builtin_popcount(s) << '\n';
			for (int j = 0; j < n; ++j)
				if ((1 << j) & s)
					cout << j + 1 << ' ';
			return 0;
		}
	}
	cout << -1;
	return 0;
}
