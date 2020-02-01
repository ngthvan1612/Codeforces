///created: 1/Jul/2019 16:03:46

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
	string s;
	typedef pair<char, int> ci;
	vector<ci> f;
	cin >> s;
	s += "$";
	for (int i = 0, last = 0, cnt = 0; i < int(s.length()); ++i) {
		if (s[i] == last) cnt++;
		else {
			if (last != 0)
				f.push_back(ci(last, cnt));
			cnt = 1;
			last = s[i];
		}
	}
	for (int i = 0, cnt_last = 0; i < int(f.size()); ++i) {
		if (cnt_last == 2) {
			cout << f[i].first;
			cnt_last = 1;
		}
		else {
			for (int j = 0; j < min(2, f[i].second); ++j) {
				cout << f[i].first;
				cnt_last = j + 1;
			}
		}
	}
	return 0;
}