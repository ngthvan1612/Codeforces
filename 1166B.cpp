#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, r, c, curr[10001];
	const char ve[] = { 'a', 'o', 'e', 'u', 'i' };
	int sz = sizeof ve / sizeof ve[0];
	bool testok = 0;
	cin >> n;
	for (int i = 5; i <= n - 1; ++i)
		if (n % i == 0 && n / i >= 5) {
			r = i;
			c = n / i;
			testok = 1;
			break;
		}
	if (!testok) { cout << -1; return 0; }
	for (int i = 0; i < c; ++i)
		curr[i] = i % sz;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			printf("%c", ve[curr[j]]);
			curr[j] = (curr[j] + 1) % sz;
		}
	}	
	return 0;
}
