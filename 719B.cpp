///created: 2/Jul/2019 13:56:35

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
int n;

int solve(char f) {
	char s = ((f == 'b') ? 'r' : 'b');
	int fs = 0, sf = 0;
	for (int i = 1; i <= n; ++i)
		if (i % 2 == 1) {
			if (a[i] != f)
				sf++;
		}
		else {
			if (a[i] != s)
				fs++;
		}
	int m = min(fs, sf);
	debug(fs, sf);
	fs -= m;
	sf -= m;
	return fs + sf + m;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d\n%s", &n, a + 1);
	cout << min(solve('b'), solve('r'));
	return 0;
}
