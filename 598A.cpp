#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int builtin_popcount(ll x) {
	int cnt = 0;
	while (x > 0) { cnt++; x /= 2; }
	return cnt;
}

int main() {
	int n;
	for (cin >> n; n--;) {
		ll x;
		cin >> x;
		x = x * (x + 1) / 2 -  2 * ((1 << builtin_popcount(x)) - 1);
		cout << x << '\n';
	}
	return 0;
}

