///created: 30/May/2019 19:07:56

#include <bits/stdc++.h>

using namespace std;

int main() {
	typedef long long ll;
	ll n, a, b, c, f[4];
	cin >> n >> a >> b >> c;
	f[0] = 0;
	f[1] = min(b + c, min(a, c * 3));
	f[2] = min(c * 2, min(a * 2, b));
	f[3] = min(a * 3, min(b + a, c));
	cout << f[(4 - n % 4) % 4];
	return 0;
}
