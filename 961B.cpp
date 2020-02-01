///created: 1/Jul/2019 15:11:05

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
int n, k, a[N], t[N];
int pre[N], suf[N], dp[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> t[i];
	pre[0] = suf[n + 1] = dp[0] = 0;
	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] + t[i] * a[i];
	for (int j = n; j >= 1; --j)
		suf[j] = suf[j + 1] + t[j] * a[j];
	for (int i = 1; i <= n; ++i)
		dp[i] = dp[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n - k + 1; ++i)
		ans = max(ans, pre[i - 1] + dp[i + k - 1] - dp[i - 1] + suf[i + k]);
	cout << ans;
	return 0;
}
