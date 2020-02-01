///created: 28/Jun/2019 12:39:37

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

int n, m, b[101][101], a[101][101] = {0};
int mark_row[101] = {0}, mark_col[101] = {0};
int c[101][101] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		bool mk = 1;
		for (int j = 1; j <= n; ++j) {
			cin >> b[i][j];
			mk &= b[i][j];
		}
		mark_row[i] = mk;
	}
	for (int j = 1; j <= n; ++j) {
		int mk = 1;
		for (int i = 1; i <= m; ++i)
			mk &= b[i][j];
		mark_col[j] = mk;
	}
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (mark_row[i] && mark_col[j])
				a[i][j] = 1;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= m; ++k)
				c[i][j] |= a[k][j];
			for (int k = 1; k <= n; ++k)
				c[i][j] |= a[i][k];
			if (b[i][j] != c[i][j]) {
				cout << "NO";
				return 0;
			}
		}
	printf("YES\n");
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			printf("%d%s", a[i][j], j == n ? "\n" : " ");
	return 0;
}
