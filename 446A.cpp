///created: 27/Jun/2019 19:46:03

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

int a[100005], n;
int f[100005], g[100005];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	if (n <= 2) { cout << n; return 0; }
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	f[1] = g[n] = 1;
	int ans = 0;
	for (int i = 2; i <= n; ++i)
		if (a[i - 1] < a[i])
			f[i] = f[i - 1] + 1;
		else f[i] = 1;
	for (int i = n - 1; i >= 1; --i)
		if (a[i] < a[i + 1])
			g[i] = g[i + 1] + 1;
		else
			g[i] = 1;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, max(f[i], g[i]));
		if (i < n) ans = max(ans, f[i] + 1);
		if (i > 1) ans = max(ans, g[i] + 1);
	}
	for (int i = 2; i <= n - 1; ++i)
		if (a[i + 1] - a[i - 1] >= 2)
			ans = max(ans, g[i + 1] + f[i - 1] + 1);
	cout << ans;			
	return 0;
}
