///created: 24/Jun/2019 18:38:57

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

int l[6];
bool check(int a, int b) {
	for (int i = a + 1; i <= b; ++i)
		if (l[a] != l[i])
			return false;
	return true;	
}

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	int cnt[10] = {0};
	set<int> st;
	for (int i = 0; i < 6; ++i) {
		cin >> l[i];
		cnt[l[i]]++;
		st.insert(l[i]);
	}
	bool c4 = 0;
	for (int i = 1; i <= 9; ++i)
		if (cnt[i] >= 4) {
			c4 = 1;
			cnt[i] -= 4;
		}
	if (c4) {
		vector<int> r;
		for (int i = 1; i <= 9; ++i)
			for (int j = 0; j < cnt[i]; ++j)
				r.push_back(i);
		if (int(r.size()) > 2) cout << "Alien";
		else if (r[0] == r[1]) cout << "Elephant";
		else cout << "Bear";
	}
	else cout << "Alien";
	return 0;
}
