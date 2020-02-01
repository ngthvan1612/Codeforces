///created: 6/Jul/2019 15:34:17

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int modulo = 1e9 + 7;

#ifdef LOCAL_DEBUG_NTV1612
string to_string(string a) { return "'" + a + "'"; }
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

string get_min(const string& a) {
	if (int(a.length()) % 2 == 1)
		return a;
	string a1 = get_min(a.substr(0, a.length() / 2));
	string a2 = get_min(a.substr(a.length() / 2, a.length() / 2));
	if (a1 < a2) return a1 + a2;
	return a2 + a1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string a, b;
	cin >> a >> b;
	a = get_min(a);
	b = get_min(b);
	debug(a, b);
	if (a == b) cout << "YES";
	else cout << "NO";
	return 0;
}
