///created: 1/Jun/2019 13:54:19

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

ll cel(ll a, ll b) { return a / b + (a % b != 0); }

int main() {
	ll n, k;
	cin >> n >> k;
	cout << cel(2 * n, k) + cel(5 * n, k) + cel(8 * n, k);
	return 0;
}
