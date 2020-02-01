///created: 30/Jun/2019 14:22:45

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

ll fpow(ll a, ll p) {
	if (p == 1) return a;
	ll tmp = fpow(a, p / 2);
	tmp = tmp * tmp;
	if (p % 2) tmp *= a;
	return tmp;
}

ll sum(ll x) {
	ll res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll a, b, c;
	const ll low = 1;
	const ll high = 1e9 - 1;
	cin >> a >> b >> c;
	vector<ll> ans;
	for (int i = 1; i <= 81; ++i) {
		ll s = b * fpow(i, a) + c;
		if (low <= s && s <= high && i == sum(s))
			ans.push_back(s);
	}
	cout << int(ans.size()) << '\n';
	for (ll v : ans)
		cout << v << ' ';
	return 0;
}
