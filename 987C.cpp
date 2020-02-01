///created: 10/Jul/2019 13:02:08

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

const int N = 3e3 + 3;
int s[N], c[N], n;
ll f[N][3];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> s[i];
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j < 3; ++j)
			f[i][j] = 1e15;
	for (int i = 1; i <= n; ++i)
		f[i][0] = c[i];
	ll ans = 1e15;
	for (int j = 1; j < 3; ++j)
		for (int i = 1; i <= n; ++i) {
			for (int k = 1; k < i; ++k)
				if (s[k] < s[i])
					f[i][j] = min(f[i][j], c[i] + f[k][j - 1]);
			if (j == 2)
				ans = min(ans, f[i][j]);
		}
	cout << (ans == 1e15 ? -1 : ans);
	return 0;
}
