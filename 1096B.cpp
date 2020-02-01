///created: 2/Jul/2019 20:42:44

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int modulo = 998244353;

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
	int n, ans = 0, i, j;
	string a;
	set<char> st;
	cin >> n >> a;
	for (char c : a)
		st.insert(c);
	i = 0, j = n - 1;
	while (i + 1 < n && a[i] == a[i + 1])
		++i;
	while (j > 0 && a[j] == a[j - 1])
		--j;
	if (a[0] != a[n - 1])
		cout << i + 2 + n - j + 1 - 1;
	else {
		if (int(st.size()) == 1) cout << 1LL * n * (n + 1) % (1LL * modulo);
		else cout << 1LL * (i + 2) * (n - j + 1) % (1LL * modulo);
	}
	return 0;
}
