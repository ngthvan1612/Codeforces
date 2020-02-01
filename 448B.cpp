///created: 27/Jun/2019 16:00:44

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
	string s, t;
	cin >> s >> t;
	int cnt[256][2] = {0}, f[101][101] = {0};
	for (char c : s)
		cnt[c][0]++;
	for (char c : t)
		cnt[c][1]++;
	bool equal_all = true;
	for (int i = 0; i < 256; ++i)
		if (cnt[i][0] < cnt[i][1]) {
			cout << "need tree";
			return 0;
		}
		else if (cnt[i][0] > cnt[i][1]) {
			equal_all = false; ///need automaton
		}
	if (equal_all) cout << "array";
	else {
		for (int i = 1; i <= int(s.length()); ++i)
			for (int j = 1; j <= int(t.length()); ++j)
				if (s[i - 1] == t[j - 1])
					f[i][j] = f[i - 1][j - 1] + 1;
				else
					f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		if (f[int(s.length())][int(t.length())] != int(t.length()))
			cout << "both";
		else cout << "automaton";
	}
	return 0;
}
