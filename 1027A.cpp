///created: 27/Jun/2019 11:05:00

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

const int change[] = { -1, +1 };

bool check(char a, char b) {
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			if (a + change[i] == b + change[j])
				return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	for (cin >> T; T--;) {
		int n;
		string s;
		cin >> n >> s;
		int i = 0, j = n - 1;
		bool ans = true;
		while (i < j) {
			if (!check(s[i], s[j])) {
				ans = false;
				break;
			}
			++i;
			--j;
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
	return 0;
}
