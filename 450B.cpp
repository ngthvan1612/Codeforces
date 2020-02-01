///created: 1/Jun/2019 22:08:32

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int mod = 1e9 + 7;

void add(int& a, int b) {
	a += b;
	if (a > b) a -= mod;
	if (a < 0) a += mod;
}

int main() {
	int x, y, n, f[10];
	cin >> x >> y >> n;
	f[0] = (x + mod) % mod;
	f[1] = (y + mod) % mod;
	for (int i = 2; i < 6; ++i)
		f[i] = (f[i - 1] - f[i - 2] + mod) % mod;
	n--;
	cout << f[n % 6];
	return 0;
}
