///created: 2/Jul/2019 09:59:01

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

const int N = 2e5 + 5;
int f[N][26] = {0}, tmp[26] = {0};
int n;
string s;

void assign_name(string name) {
	memset(tmp, 0, sizeof tmp);
	for (char c : name)
		tmp[c - 'a']++;
}

bool check(int pf) {
	for (int j = 0; j < 26; ++j)
		if (f[pf][j] < tmp[j])
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	s = "$" + s;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 26; ++j)
			f[i][j] = f[i - 1][j];
		f[i][s[i] - 'a']++;
	}
	string name;
	int t;
	for (cin >> t; t--;) {
		cin >> name;
		assign_name(name);
		int L = 1, R = n, res = -1;
		while (L <= R) {
			int mid = (L + R) / 2;
			if (check(mid)) { R = mid - 1; res = mid; }
			else L = mid + 1;
		}
		assert(res > 0);
		cout << res << '\n';
	}
	return 0;
}
