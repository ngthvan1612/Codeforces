///created: 28/Jun/2019 14:50:29

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

char a[55][55] = {0};
int n, m, vs[55][55] = {0};
bool ans = false;
const int hor[] = { 0, 0, -1, 1 };
const int ver[] = { -1, 1, 0, 0 };

void dfs(int x, int y, char col, int cnt, int px, int py) {
	vs[x][y] = 1;
	for (int k = 0; k < 4; ++k) {
		int u = x + hor[k];
		int v = y + ver[k];
		if (a[u][v] == col) {
			if (vs[u][v]) {
				if (cnt >= 4 && px != u || py != v) {
					ans = true;
					debug(u, v, px, py);
				}
			}
			else
				dfs(u, v, col, cnt + 1, x, y);
		}
	}
}

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s", a[i] + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (!vs[i][j]) {
				debug(1, i, j);
				dfs(i, j, a[i][j], 1, -1, -1);
		 	}
	printf(ans ? "Yes" : "No");
	return 0;
}
