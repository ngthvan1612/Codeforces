///created: 24/Jun/2019 23:30:08

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

int n, m;
char a[105][105] = {0};
const char* v = "BW";
const int hor[] = { 0, 0, -1, 1 };
const int ver[] = { -1, 1, 0, 0 };

void dfs(int i, int j, int c) {
	if (i < 1 || i > n || j < 1 || j > m) return;
	a[i][j] = v[c];
	for (int k = 0; k < 4; ++k)
		if (a[i + hor[k]][j + ver[k]] == '.')
			dfs(i + hor[k], j + ver[k], c ^ 1);
}

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%d", &n, &m);
	ii s;
	bool first = true;
	for (int i = 1; i <= n; ++i)
		scanf("%s", a[i] + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == '.')
				dfs(i, j, 0);
	for (int i = 1; i <= n; ++i)
		printf("%s\n", a[i] + 1);
	return 0;
}
