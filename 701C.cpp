///created: 30/Jun/2019 20:01:31

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
	int sz = 0, n, cnt[256] = {0};
	cin >> n >> s;
	set<char> st;
	for (char &c : s)
		st.insert(c);
	sz = int(st.size());
	st.clear();
	int ans = 1e9;
	debug(sz);
	for (int i = 0, j = 0; i < n; ++i) {
		cnt[s[i]]++;
		st.insert(s[i]);
		while (int(st.size()) == sz) {
			if (cnt[s[j]] == 1)
				st.erase(s[j]);
			cnt[s[j]]--;
			if (int(st.size()) < sz) {
				cnt[s[j]]++;
				st.insert(s[j]);
				break;
			}
			++j;
		}
		debug(i, j, st.size());
		if (int(st.size()) == sz)
			ans = min(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}
