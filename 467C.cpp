///created: 3/Jul/2019 11:00:53

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

int n, a[5001], m, k;
ll f[5001], dp[5001][5001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	f[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= k; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (i - m + 1 >= 1)
				dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + f[i] - f[i - m]);
		}
	cout << dp[n][k];
	return 0;
}
