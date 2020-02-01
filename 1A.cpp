#include <bits/stdc++.h>

using namespace std;

int main() {
	typedef long long ll;
	ll n, m, a;
	cin >> n >> m >> a;
	if (n % a != 0) n = (n / a + 1) * a;
	if (m % a != 0) m = (m / a + 1) * a;
	cout << m * n / (a * a);
	return 0;
}
