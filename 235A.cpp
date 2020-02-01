///created: 3/Jul/2019 11:54:42

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

ll lcm(ll a, ll b) {
	return a * b / __gcd(a, b);
}

ll bf(ll n) {
	ll ans = 1;
	for (ll i = 1; i <= n; ++i)
		for (ll j = 1; j <= n; ++j)
			for (ll k = 1; k <= n; ++k) {
				ans = max(ans, lcm(lcm(i, j), k));
			}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	if (n == 1) cout << 1;
	else if (n == 2) cout << 2;
	else if (n == 3) cout << 6;
	else if (n % 2) cout << n * (n - 1) * (n - 2);
	else if (n % 3) cout << n * (n - 1) * (n - 3);
	else cout << (n - 1) * (n - 2) * (n - 3);	
//	debug(bf(n));
	return 0;
}
