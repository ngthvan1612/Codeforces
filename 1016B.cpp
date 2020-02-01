///created: 2/Jul/2019 13:24:09

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

const int N = 1e3 + 5;
char s[N], t[N];
int n, m, q, f[N];

bool is_substr(int i) {
	if (i + m - 1 > n) return false;
	for (int z = 1; z <= m; ++z)
		if (s[i + z - 1] != t[z])
			return false;
	return true;	
}

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%d%d\n%s\n%s", &n, &m, &q, s + 1, t + 1);
	f[0] = 0;
	for (int i = 1; i <= n; ++i)
		f[i] = f[i - 1] + int(is_substr(i));
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (r - l + 1 >= m)
			printf("%d\n", f[r - m + 1] - f[l - 1]);
		else
			printf("0\n");
	}
	return 0;
}
