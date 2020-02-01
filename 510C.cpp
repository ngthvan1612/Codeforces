///created: 3/Jul/2019 12:27:40

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int modulo = 1e9 + 7;

#ifdef LOCAL_DEBUG_NTV1612
string to_string(const char* s) { return to_string(s); }
string to_string(string s) { return s; }
string to_string(char c) { return string(c, 1); }
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

string a[101];
vector<char> g[256];
int n, deg[256];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	memset(deg, 0, sizeof deg);
	for (int i = 1; i <= n - 1; ++i) {
		int m = int(min(a[i].length(), a[i + 1].length()));
		bool is_prefix = (a[i].length() > a[i + 1].length());
		for (int j = 0; j < m; ++j)
			if (a[i][j] != a[i + 1][j]) {
				is_prefix = false;
				g[a[i][j]].push_back(a[i + 1][j]);
				deg[a[i + 1][j]]++;
				break;
			}
		if (is_prefix) {
			cout << "Impossible";
			return 0;
		}
	}
	///TOPO SORT
	string L;
	queue<char> S;
	for (char c = 'a'; c <= 'z'; ++c)
		if (deg[c] == 0)
			S.push(c);
	while (!S.empty()) {
		char t = S.front(); S.pop();
		L.push_back(t);
		for (char v : g[t]) {
			deg[v]--;
			if (deg[v] == 0)
				S.push(v);
		}			
	}
	for (char c = 'a'; c <= 'z'; ++c)
		if (deg[c]) {
			cout << "Impossible";
			return 0;
		}
	cout << L;
	return 0;
}
