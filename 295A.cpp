///created: 6/Jul/2019 21:28:05

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

const int N = 1e5 + 5;
ll a[N], dp[N] = {0};
int n, m, k, l[N], r[N], d[N], f[N] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> l[i] >> r[i] >> d[i];
	for (int i = 1; i <= k; ++i) {
		int x, y;
		cin >> x >> y;
		f[x]++;
		f[y + 1]--;
	}
	for (int i = 1; i <= m; ++i)
		f[i] += f[i - 1];
	for (int i = 1; i <= m; ++i) {
		dp[l[i]] += 1LL * f[i] * d[i];
		dp[r[i] + 1] -= 1LL * f[i] * d[i];
	}
	for (int i = 1; i <= n; ++i) {
		dp[i] += dp[i - 1];
		cout << a[i] + dp[i] << ' ';
	}
	return 0;
}
