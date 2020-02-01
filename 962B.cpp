///created: 23/Jun/2019 12:57:37

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

const int N = 2e5 + 5;
char s[N];
int n, a, b;

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%d%d\n%s", &n, &a, &b, s + 1);
	int p = -1, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '*') p = -1;
		else {
			if (p == -1) {
				if (b > a) b--, ans++, p = 2;
				else if (a) a--, ans++, p = 1;
			}
			else if (p == 1) { ///pre = A
				if (b) b--, ans++;
				p = 2;
			}
			else { ///pre = B
				if (a) a--, ans++;
				p = 1;
			}
		}
	}
	cout << ans;
	return 0;
}
