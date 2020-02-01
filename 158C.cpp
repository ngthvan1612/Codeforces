///created: 10/Jul/2019 17:45:39

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int modulo = 1e9 + 7;

#ifdef LOCAL_DEBUG_NTV1612
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
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
	int t;
	string dir = "/";
	for (cin >> t; t--;) {
		string cmd, s;
		cin >> cmd;
		if (cmd == string("pwd")) {
			cout << dir << '\n';
		}
		else {
			cin >> s;
			s += "/";
			bool goRoot = (s[0] == '/');
			if (goRoot) dir = "/";
			string c;
			for (int i = int(goRoot); i < int(s.length()); ++i)
				if (s[i] != '/')
					c.push_back(s[i]);
				else {
					if (c == string("..")) {
						if (dir.size() == 1) continue;
						else
							dir.pop_back();
							while (dir.back() != '/')
								dir.pop_back();
					}
					else {
						dir += c;
						dir.push_back('/');
					}
					c.clear();
				}
		}
	}
	return 0;
}
