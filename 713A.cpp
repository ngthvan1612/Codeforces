///created: 2/Jul/2019 18:14:29

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

map<string, int> cnt;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		string val, w;
		char op;
		cin >> op >> val;
		for (char c : val)
			w.push_back('0' + (c - '0') % 2);
		reverse(w.begin(), w.end());
		if (op == '+') {
			debug("INSERT: ", w);
			while (int(w.size()) <= 18) {
				cnt[w]++;
				w.push_back('0');
			}
		}
		else if (op == '-') {
			debug("REMOVE: ", w);
			while (int(w.size()) <= 18) {
				cnt[w]--;
				w.push_back('0');
			}
		}
		else {
			debug("QUERY: ", val);
			reverse(val.begin(), val.end());
			int res = 0;
			while (int(val.size()) < 18)
				val.push_back('0');
			cout << cnt[val] << '\n';
		}
	}
	return 0;
}
