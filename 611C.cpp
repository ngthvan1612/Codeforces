///created: 7/Jul/2019 09:15:21

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

const int N = 5e2 + 3;
int h, w, q, hor[N][N], ver[N][N];
char a[N][N];

int main() {
	memset(hor, 0, sizeof hor);
	memset(ver, 0, sizeof ver);
	scanf("%d%d", &h, &w);
	for (int i = 1; i <= h; ++i)
		scanf("%s", a[i] + 1);
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			hor[i][j] = hor[i - 1][j] + hor[i][j - 1] - hor[i - 1][j - 1];
			ver[i][j] = ver[i - 1][j] + ver[i][j - 1] - ver[i - 1][j - 1];
			if (a[i][j] == '.' && a[i + 1][j] == '.')
				ver[i][j]++;
			if (a[i][j] == '.' && a[i][j + 1] == '.')
				hor[i][j]++;
		}
	}
	scanf("%d", &q);
	while (q--) {
		int r1, c1, r2, c2;
		scanf("%d%d %d%d\n", &r1, &c1, &r2, &c2);
		int h = hor[r2][c2 - 1] - hor[r1 - 1][c2 - 1] - hor[r2][c1 - 1] + hor[r1 - 1][c1 - 1];
		int v = ver[r2 - 1][c2] - ver[r1 - 1][c2] - ver[r2 - 1][c1 - 1] + ver[r1 - 1][c1 - 1];
		printf("%d\n", h + v);
	}
	return 0;
}
