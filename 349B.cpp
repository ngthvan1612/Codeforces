///created: 3/Jul/2019 19:20:55

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
template<class __Ty> bool maxi(__Ty& a, __Ty b) { return a <= b ? ((a = b) | 1) : (0); }
template<class __Ty> __Ty add(__Ty a, __Ty b) { return (a + b) % (__Ty(modulo)); }
template<class __Ty> __Ty sub(__Ty a, __Ty b) { __Ty m(modulo); return ((a - b) % m + m) % m; }

int v, a[10], pos = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> v;
	for (int i = 1; i <= 9; ++i) {
		cin >> a[i];
		if (pos == 0 || a[pos] >= a[i])
			pos = i;
	}
	int m = v / a[pos];
	if (!m) cout << -1;
	else {
		while (m--) {
			int lmax = a[pos] + v - (m + 1) * a[pos];
			for (int j = 9; j >= 1; --j)
				if (a[j] <= lmax) {
					printf("%d", j);
					v -= a[j];
					break;
				}
		}
	}
	return 0;
}
