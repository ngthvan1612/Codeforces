///created: 29/Jun/2019 20:12:31

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int modulo = 1e9 + 7;

#ifdef LOCAL_DEBUG_NTV1612
template<class __Ty>
string to_string(__Ty a) {
	string res = "[ ";
	bool f = true;
	for (auto &p : a) { res += (f ? string("") : string(", ")) + to_string(p); f = false;	}
	return res + " ]";
}
void _debug() { fprintf(stderr, "\n"); }
template<typename __Ty_head, typename... __Ty_tail>
void _debug(__Ty_head head, __Ty_tail... tail) { fprintf(stderr, "%s ", to_string(head).c_str()); _debug(tail...); }
#define debug(...) fprintf(stderr, "DEBUG [%s]: ", #__VA_ARGS__), _debug(__VA_ARGS__)
#else
#define debug(...) 0
#endif

template<class __Ty> bool mini(__Ty& a, __Ty b) { return a > b ? ((a = b) | 1) : (0); }
template<class __Ty> bool maxi(__Ty& a, __Ty b) { return a < b ? ((a = b) | 1) : (0); }
template<class __Ty> __Ty add(__Ty a, __Ty b) { return (a + b) % (__Ty(modulo)); }
template<class __Ty> __Ty sub(__Ty a, __Ty b) { __Ty m(modulo); return ((a - b) % m + m) % m; }

ll calc(ll n, ll k) {
	ll m = n / __gcd(n, k);
	return 1LL * m + 1LL * k * (m - 1) * m / 2;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, g, m, k;
	cin >> n;
	vector<ll> ans;
	for (int k = 1; k * k <= n; ++k)
		if (n % k == 0) {
			ans.push_back(calc(n, k));
			if (k != n / k)
				ans.push_back(calc(n, n / k));
		}
	sort(ans.begin(), ans.end());
	for (ll v : ans)
		cout << v << ' ';
	return 0;
}
