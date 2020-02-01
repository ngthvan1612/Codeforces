///created: 29/Jun/2019 12:41:28

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

ll check(ll p) {
	ll c = ll(sqrt(p));
	return c * c == p;
}

ll find_m(ll n) {
	for (ll i = 1; i * i < n; ++i)
		if (check(n - i * i))
			return i * i;
	return -1;
}

ll pow2(ll n) { return n * n; }

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	ll a, b, c;
	cin >> a;
	if (a % 2) {
		b = (a * a - 1) / 2;
		c = (a * a + 1) / 2;
	}
	else {
		b = a * a / 4 - 1;
		c = a * a / 4 + 1;
	}
	if (b < 1 || c < 1) cout << -1;
	else cout << b << ' ' << c;
	return 0;
}