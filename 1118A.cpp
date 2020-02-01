///created: 1/Jun/2019 15:01:02

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;		
	ll n, a, b;
	for (cin >> q; q--;) {
		cin >> n >> a >> b;
		cout << min(a * n, b * (n / 2) + a * (n % 2 != 0)) << '\n';
	}
	return 0;
}
