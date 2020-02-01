#include <bits/stdc++.h>

using namespace std;

long long f[47];

int main() {
	int n;
	cin >> n;
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= 45; ++i)
		f[i] = f[i - 1] + f[i - 2];
	for (int i = 0; i <= 45; ++i)
		for (int j = 0; j <= 45; ++j)
			for (int k = 0; k <= 45; ++k)
				if (f[i] + f[j] + f[k] == 1LL * n) {
					cout << f[i] << ' ' << f[j] << ' ' << f[k];
					return 0;
				}
	cout << "I'm too stupid to solve this problem";
	return 0;
}
