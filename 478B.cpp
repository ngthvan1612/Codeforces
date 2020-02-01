///created: 27:04:2019 20:10:04

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n, m;
	cin >> n >> m;
	///calc min
	cout << (n / m) * (n / m - 1) / 2 * m + (n % m) * (n / m) << ' ';
	///calc max
	cout << (n - m + 1) * (n - m) / 2;
	return 0;
}
