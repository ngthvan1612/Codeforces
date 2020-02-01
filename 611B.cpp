///created: 8/Jul/2019 11:01:24

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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll a, b;
	cin >> a >> b;
	///gen
	vector<ll> f;
	for (int i = 1; i <= 60; ++i) {
		ll b = (1LL << i) - 1;
		for (int j = 0; j < i - 1; ++j) {
			f.push_back(b ^ (1LL << j));
		}
	}
	sort(f.begin(), f.end());
	int k1 = lower_bound(f.begin(), f.end(), a) - f.begin();
	int k2 = upper_bound(f.begin(), f.end(), b) - 1 - f.begin();
	cout << k2 - k1 + 1;
	return 0;
}
