///created: 22/Jun/2019 17:30:33

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int modulo = 1e9 + 7;

template<class __Ty>
string to_string(__Ty a) {
	string res = "[ ";
	bool f = true;
	for (auto &p : a) {
		res += (f ? string("") : string(", ")) + to_string(p);
		f = false;
	}
	return res + " ]";
}
void _debug() { fprintf(stderr, "\n"); }
template<typename __Ty_head, typename... __Ty_tail>
void _debug(__Ty_head head, __Ty_tail... tail) {
	fprintf(stderr, "%s ", to_string(head).c_str());
	_debug(tail...);
}
#define debug(...) fprintf(stderr, "DEBUG [%s]: ", #__VA_ARGS__), _debug(__VA_ARGS__)

template<class __Ty> bool mini(__Ty& a, __Ty b) { return a > b ? ((a = b) | 1) : (0); }
template<class __Ty> bool maxi(__Ty& a, __Ty b) { return a < b ? ((a = b) | 1) : (0); }
template<class __Ty> __Ty add(__Ty a, __Ty b) { return (a + b) % (__Ty(modulo)); }
template<class __Ty> __Ty sub(__Ty a, __Ty b) { __Ty m(modulo); return ((a - b) % m + m) % m; }

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int m, s, a, b;
	char amin[105] = {0}, amax[105] = {0};
	cin >> m >> s;
	if (m == 1 && s == 0) {
		printf("0 0");
		return 0;
	}
	if (s > m * 9 || s == 0) {
		printf("-1 -1");
		return 0;
	}
	a = b = s;
	amin[1] = max(1, s - (m - 1) * 9) + '0';
	a -= amin[1] - '0';
	for (int i = m; i >= 2; --i) {
		amin[i] = min(9, a) + '0';
		a -= min(9, a);
	}
	for (int i = 1; i <= m; ++i) {
		amax[i] = min(9, b) + '0';
		b -= min(9, b);
	}
	printf("%s\n%s", amin + 1, amax + 1);
	return 0;
}
