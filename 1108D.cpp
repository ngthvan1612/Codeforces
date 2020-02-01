///created: 27/Jun/2019 19:32:26

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

const int N = 2e5 + 5;
char a[N], ans[N];
int n, f[N][3], trace[N][3];

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%s", &n, a + 1);
	const char* s = "RGB";
	for (int i = 0; i < 3; ++i)
		f[0][i] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			f[i][j] = 1e9 + 7;
			for (int k = 0; k < 3; ++k)
				if (k != j) {
					if (mini(f[i][j], f[i - 1][k]))
						trace[i][j] = k;
				}
			f[i][j] += (s[j] != a[i]);
		}
	}
	int p = min(f[n][0], min(f[n][1], f[n][2])), t;
	for (int j = 0; j < 3; ++j)
		if (f[n][j] == p)
			t = j;
	ans[n + 1] = 0;
	while (n) {
		ans[n] = s[t];
		t = trace[n][t];
		n--;
	}
	printf("%d\n%s", p, ans + 1);
	return 0;
}
