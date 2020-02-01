///created: 30/Jun/2019 11:15:08

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

const int N = 1e2 + 5;
int n, m, d, a[N][N], cnt[10005] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> d;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			if (a[i][j] % d != a[1][1] % d) {
				cout << -1;
				return 0;
			}
			cnt[a[i][j]]++;
		}
	int ans = 1e9 + 7;
	for (int i = 1; i <= 10000; ++i)
		if (cnt[i]) {
			int res = 0;
			for (int j = 1; j <= 10000; ++j)
				if (cnt[j] && i != j)
					res = res + cnt[j] * abs(j - i) / d;
			ans = min(ans, res);
		}
	cout << ans;
	return 0;
}
