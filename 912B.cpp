///created: 10/Jul/2019 13:12:53

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

int bf(int n, int k) {
	debug(n, k);
	int ans = 0;
	for (int s = 0; s < (1 << n); ++s) {
		int p = 0;
		if (__builtin_popcount(s) != k) continue;
		for (int j = 0; j < n; ++j)
			if ((1 << j) & s)
				p ^= (j + 1);
		ans = max(ans, p);
		if (ans == 15) cout << "s = " << s << '\n';
	}		
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, k;
	cin >> n >> k;
	int high = 0;
	while ((1LL << high) < n)
		++high;
	while ((1LL << high) > n)
		--high;
 	if (k > 1)
		cout << (1LL << (high + 1)) - 1;
	else cout << n;
	return 0;
}
