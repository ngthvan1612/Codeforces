///created: 4/Jul/2019 12:55:37

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

ll cnt[3], p[3], n[3], r;

bool check(ll v) {
	ll res = 0;
	for (int i = 0; i < 3; ++i)
		res += max(0LL, cnt[i] * v - n[i]) * p[i];
	return res <= r;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	memset(cnt, 0, sizeof cnt);
	string s;
	cin >> s;
	for (int i = 0; i < int(s.length()); ++i)
		if (s[i] == 'B') cnt[0]++;
		else if (s[i] == 'S') cnt[1]++;
		else cnt[2]++;
	for (int i = 0; i < 3; ++i)
		cin >> n[i];
	for (int i = 0; i < 3; ++i)
		cin >> p[i];
	cin >> r;
	ll left = 0, right = 1e13, ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (check(mid)) { ans = mid; left = mid + 1; }
		else right = mid - 1;
	}
	cout << ans;
	return 0;
}
