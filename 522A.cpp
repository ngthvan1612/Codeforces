///created: 27/Jun/2019 20:02:34

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

int f[201] = {0};
vector<int> g[201];

int dfs(int u) {
	f[u] = 0;
	for (int v : g[u])
		if (f[v])
			f[u] = max(f[u], f[v]);
		else
			f[u] = max(f[u], dfs(v));
	return f[u] + 1;
}

string repair(string a) {
	for (char &c : a)
		if ('a' <= c && c <= 'z')
			c -= 32;
	return a;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, cnt = 1;
	cin >> n;
	map<string, int> re;
	re["POLYCARP"] = 1;
	for (int i = 1; i <= n; ++i) {
		string a, b, c;
		cin >> a >> b >> c;
		a = repair(a);
		c = repair(c);
		int u = re[a], v = re[c];
		if (u == 0)
			u = re[a] = ++cnt;
		assert(v != 0);
		g[v].push_back(u);
	}
	cout << dfs(1);
	return 0;
}
