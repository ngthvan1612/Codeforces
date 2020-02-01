///created: 28/Jun/2019 16:41:01

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

const int N = 1001;
ll row[N], col[N];
ll a[N][N];
int n, x, y;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	if (n == 1) { cout << 1; return 0; }
	bool ts = 0;
	ll &cc = a[n + 1][n + 1], &cp = a[n + 1][n + 2];
	cc = cp = 0;
	assert(n != cc);
	memset(a, -1, sizeof a);
	for (int i = 1; i <= n; ++i)
		row[i] = col[i] = 0LL;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				x = i;
				y = j;
			}
			col[j] += a[i][j];
			row[i] += a[i][j];
			if (i == j)
				cc += a[i][j];
			if (j == n - i + 1)
				cp += a[i][j];
		}
	}
	bool pretest = true;
	int px = (x < n) ? x + 1 : 1;
	int py = (y < n) ? y + 1 : 1;
	ll ans = row[px] - row[x];
	a[x][y] = ans;
	debug(ans);
	for (int i = 1; i <= n; ++i)
		row[i] = col[i] = 0;
	cc = cp = 0;
	if (ans <= 0) { cout << -1; return 0; }
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			row[i] += a[i][j];
			col[j] += a[i][j];
			if (i == j)
				cc += a[i][j];
			if (j == n - i + 1)
				cp += a[i][j];
		}
	}
	bool testok = true;
	for (int i = 1; i <= n; ++i)
		testok &= ((row[i] == row[1]) && (col[i] == col[1]));
	if (testok && cc == cp && row[1] == cc && cp == col[1])
		cout << ans;
	else cout << -1;
	return 0;
}
