///created: 27/Jun/2019 20:42:39

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int modulo = 1e8;

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

int f[101][101][2] = {0};
int n1, n2, k1, k2;

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	cin >> n1 >> n2 >> k1 >> k2;
	f[0][0][0] = f[0][0][1] = 1;
	for (int i = 0; i <= n1; ++i)
		for (int j = 0; j <= n2; ++j) {
			if (i == 0 && j == 0) continue;
			for (int z = 1; z <= k1 && i - z >= 0; ++z) {
				f[i][j][0] = add(f[i][j][0], f[i - z][j][1]);
			}
			for (int z = 1; z <= k2 && j - z >= 0; ++z) {
				f[i][j][1] = add(f[i][j][1], f[i][j - z][0]);
			}
		}
	cout << add(f[n1][n2][1], f[n1][n2][0]);
	return 0;
}
