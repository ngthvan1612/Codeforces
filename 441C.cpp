///created: 6/Jul/2019 19:15:00

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

const int hor[] = { 0, 1, 0, -1 };
const int ver[] = { 1, 0, -1, 0 };
int n, m, k, lr = 1, t = 0, cnt = 0;
bool vs[301][301] = {0};
ii p[300 * 300 + 1];
void dfs(int x, int y) {
	vs[x][y] = 1;
	p[++cnt] = ii(x, y);
	for (int f = 0; f < 4; ++f) {
		int u = x + hor[t], v = y + ver[t];
		if (1 <= u && u <= n && 1 <= v && v <= m && !vs[u][v]) {
			dfs(u, v);
			break;
		}
		t = (t + 1) % 4;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	dfs(1, 1);
	int f = 0;
	for (int i = 1; i < k; ++i) {
		cout << 2 << ' ';
		for (int j = 0; j < 2; ++j) {
			++f;
			cout << p[f].first << ' ' << p[f].second << (j == 1 ? '\n' : ' ');
		}
	}
	cout << m * n - f << ' ';
	while (f < m * n) {
		++f;
		cout << p[f].first << ' ' << p[f].second << ' ';
	}
	return 0;
}
