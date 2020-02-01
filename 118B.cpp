#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n + 1; ++i) {
		for (int j = 0; j < abs(i - n) * 2; ++j)
			cout << ' ';
		for (int j = 0, t = - n + abs(i - n); j < 2 * n + 1 - 2 * abs(i - n); ++j, ++t) {
			cout << - abs(t) + n - abs(i - n);
			if (j < 2 * n + 1 - 2 * abs(i - n) - 1) cout << ' ';
		}
		cout << '\n';			
	}
	return 0;
}
