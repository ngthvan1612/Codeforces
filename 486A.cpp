#include <bits/stdc++.h>

using namespace std;

int main() {
	typedef long long ll;
	ll n;
	cin >> n;
	if (n % 2 == 0) cout << n / 2;
	else cout << n / 2 - n;
	return 0;
}

