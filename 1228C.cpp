#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

vector<int> prime(int n) {
	vector<int> res;
	int k = 2;
	while (k * k <= n) {
		if (n % k == 0) {
			res.push_back(k);
			while (n % k == 0)
				n /= k;
		}
		++k;
	}
	if (n > 1)
		res.push_back(n);
	return res;
}

///calc a ^ b % mod FAST
ll fpow(ll a, ll b) {
	if (b == 0) return 1;
	ll tmp = fpow(a, b / 2);
	tmp = tmp * tmp % mod;
	if (b % 2)
		tmp = tmp * a % mod;
	return tmp;
}

int main() {
	int x;
	ll n;
	cin >> x >> n;
	vector<int> pr = prime(x);
	ll ans = 1;
	for (const ll &v : pr) {
		ll sum = 0;
		for (ll t = 1LL * v; t <= n;) {
			cerr << "t = " << t << '\n';
			sum += n / t;
			ll t_new = t * v;
			if (t_new / t != v) break;
			t = t_new;
		}
		ans = ans * fpow(v, sum) % mod;
	}
	cout << ans;
	return 0;
}
