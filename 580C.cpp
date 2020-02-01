///created: 9/Jun/2019 09:38:18

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

const int N = 1e5 + 3;
int n, m, p[N], vs[N] = {0}, meo[N] = {0};
vector<int> g[N];

int dfs(int u, int mw) {
	vs[u] = 1;
	int ans = 0, leaf = 1;
	for (int v : g[u])
		if (p[u] != v && !vs[v]) {
			leaf = 0;
			if (meo[v]) {
				if (mw + 1 <= m) {
					p[v] = u;
					vs[v] = 1;
					ans += dfs(v, mw + 1);
				}
			}
			else {
				p[v] = u;
				vs[v] = 1;
				ans += dfs(v, 0);
			}
		}
	if (leaf) {
		cerr << "leaf: " << u << '\n';
		return 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> meo[i];
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	memset(p, -1, sizeof p);
	cout << dfs(1, meo[1]);
	return 0;
}
