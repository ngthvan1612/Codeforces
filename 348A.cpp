#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n, a, mx = 0;
	ll sum = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		sum += 1LL * a;
		mx = max(mx, a);
	}
	ll res = (sum + n - 2) / (n - 1);
	cout << max(res, 1LL * mx);
	return 0;
}
