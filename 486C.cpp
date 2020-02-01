///created: 6/Jul/2019 21:00:45

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

const int N = 1e5 + 5;
char a[N];
int n, p;

int calc_diff(char u, char v) {
	int r1 = 0, r2 = 0;
	char u1 = u, u2 = u;
	while (u1 != v) {
		u1++;
		if (u1 > 'z') u1 = 'a';
		r1++;
	}
	while (u2 != v) {
		u2--;
		if (u2 < 'a') u2 = 'z';
		r2++;
	}
	return min(r1, r2);
}

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d %d\n%s", &n, &p, a + 1);
	p = min(p, n - p + 1);
	int ans = 0, dmin = 1e9, dmax = -1e9, i = 1, j = n;
	while (i < j) {
		if (a[i] != a[j]) {
			dmin = min(dmin, i);
			dmax = max(dmax, i);
			ans += calc_diff(a[i], a[j]);
		}
		++i;
		--j;
	}
	if (!ans) { cout << 0; return 0; }
	debug(ans, dmin, dmax, p);
	cout << ans + min(abs(p - dmin), abs(p - dmax)) + dmax - dmin;
	return 0;
}
