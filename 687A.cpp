///created: 12/Jun/2019 11:30:04

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';
template<class __Ty> bool minimize(__Ty& a, __Ty b) {
	if (a > b) { a = b; return true; }
	return false;
}
template<class __Ty> bool maximize(__Ty& a, __Ty b) {
	if (a < b) { a = b; return true; }
	return false;
}

const int N = 1e5 + 5;
int n, m, d[N], vs[N];
vector<int> g[N], a[3];

bool dfs(int u) {
	vs[u] = 1;
	bool res = true;
	a[d[u]].push_back(u);
	for (int v : g[u])
		if (!vs[v]) {
			d[v] = 3 - d[u];
			res &= dfs(v);
		}
		else
			if (d[v] == d[u])
				return false;
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(d, 0, sizeof d);
	memset(vs, 0, sizeof vs);
	for (int i = 1; i <= n; ++i)
		if (!vs[i]) {
			d[i] = 1;
			if (!dfs(i)) {
				cout << -1;
				return 0;
			}
		}
	cout << int(a[1].size()) << '\n';
	for (int v : a[1])
		cout << v << ' ';
	cout << '\n' << int(a[2].size()) << '\n';
	for (int v : a[2])
		cout << v<< ' ';
	return 0;
}
