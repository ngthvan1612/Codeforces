#include <bits/stdc++.h>

using namespace std;

int main() {
	typedef long long ll;
	ll n, k, w;
	cin >> k >> n >> w;
	ll need = k * w * (w + 1) / 2;
	cout << max(1LL * 0, need - n);
	return 0;
}

