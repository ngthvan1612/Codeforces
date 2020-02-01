///created: 30/Jun/2019 19:39:04

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

int p, q, l, r, a[51], b[51], c[51], d[51];
int f[1003] = {0}, g[1003] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> p >> q >> l >> r;
	for (int i = 1; i <= p; ++i) {
		cin >> a[i] >> b[i];
		f[a[i]]++;
		f[b[i] + 1]--;
	}
	for (int i = 1; i <= 1000; ++i)
		f[i] += f[i - 1];
	for (int i = 1; i <= q; ++i)
		cin >> c[i] >> d[i];
	int ans = 0;
	for (int i = l; i <= r; ++i) {
		memset(g, 0, sizeof g);
		for (int j = 1; j <= q; ++j) {
			g[c[j] + i]++;
			g[d[j] + i + 1]--;
		}
		bool testok = false;
		for (int j = 1; j <= 1000; ++j) {
			g[j] += g[j - 1];
			if (f[j] != 0 && g[j] != 0) {
				testok = true;
				break;
			}
		}
		if (testok)
			ans++;
	}
	cout << ans;
	return 0;
}
