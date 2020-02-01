///created: 24/Jun/2019 20:39:48

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

char a[505][505];
int h, w;

bool process(int x, int y) {
	if (a[x][y] != '*') return false;
	int l = y, r = y, u = x, d = x;
	while (l >= 1 && a[x][l] == '*') --l;
	while (r <= w && a[x][r] == '*') ++r;
	while (u >= 1 && a[u][y] == '*') --u;
	while (d <= h && a[d][y] == '*') ++d;
	if (l == y - 1 || r == y + 1 || u == x - 1 || d == x + 1) return false;
	for (int i = l + 1; i <= r - 1; ++i)
		a[x][i] = '.';
	for (int i = u + 1; i <= d - 1; ++i)
		a[i][y] = '.';
	return true;
}

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%d", &h, &w);
	for (int i = 1; i <= h; ++i)
		scanf("%s", a[i] + 1);
	int cnt = 0;
	for (int i = 2; i <= h - 1; ++i)
		for (int j = 2; j <= w - 1; ++j)
			if (process(i, j)) {
				cnt++;
			}
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			if (a[i][j] != '.')
				cnt = 0;
		}
	}
	if (cnt == 1) printf("YES");
	else printf("NO");
	return 0;
}
