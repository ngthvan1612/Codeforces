///created: 24/Jun/2019 14:19:20

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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int c[256] = {0};
	c['Q'] = c['q'] = 9;
	c['R'] = c['r'] = 5;
	c['b'] = c['B'] = 3;
	c['N'] = c['n'] = 3;
	c['P'] = c['p'] = 1;
	string s;
	int white = 0, black = 0;
	for (int i = 0; i < 8; ++i) {
		cin >> s;
		for (int j = 0; j < 8; ++j)
			if (s[j] != '.') {
				if ('a' <= s[j] && s[j] <= 'z') black += c[s[j]];
				else white += c[s[j]];
			}
	}
	if (white > black) printf("White");
	else if (white < black) printf("Black");
	else printf("Draw");
	return 0;
}
