///created: 9/Jul/2019 13:30:59

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
int n, id[N], order[N];
vector<int> g[N];

bool cmp(int i, int j) { return id[i] < id[j]; }

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		int p;
		cin >> p;
		id[p] = i;
	}
	for (int i = 1; i <= n; ++i)
		sort(g[i].begin(), g[i].end(), cmp);
	memset(order, 0, sizeof order);
	queue<int> Q;
	Q.push(1);
	int od = 0;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		order[u] = ++od;
		for (int v : g[u])
			if (!order[v]) {
				Q.push(v);
			}
	}
	for (int i = 1; i <= n; ++i)
		if (order[i] != id[i]) {
			cout << "No";
			return 0;
		}
	cout << "Yes";
	return 0;
}
