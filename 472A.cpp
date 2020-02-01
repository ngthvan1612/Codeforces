#include <bits/stdc++.h>

using namespace std;

int f[1000001];

int main() {
	f[0] = f[1] = 0;
	for (int i = 2; i <= 1000000; ++i) f[i] = 1;
	for (int i = 2; i * i <= 1000000; ++i)
		if (f[i])
			for (int j = i * i; j <= 1000000; j += i)
				f[j] = 0;
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i)
		if (f[i] + f[n - i] == 0) {
			cout << i << ' ' << n - i;
			return 0;
		}
	return 0;
