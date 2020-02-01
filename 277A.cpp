///created: 10/Jun/2019 17:37:25

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

const int N = 1e2 + 5;
int n, m, d[N];
vector<int> g[N];

int get(int u) {
	return d[u] = (d[u] == u ? u : get(d[u]));
}

void unite(int u, int v) {
	u = get(u);
	v = get(v);
	d[u] = v;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	int check = 0;
	for (int i = 1; i <= n; ++i)
		d[i] = i;
	for (int i = 1; i <= n; ++i) {
		int k, v;
		cin >> k;
		if (k == 0)
			check++;
		for (int j = 1; j <= k; ++j) {
			cin >> v;
			g[v].push_back(i);
		}
	}
	if (check == n) {
		cout << n;
		return 0;
	}
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j < int(g[i].size()); ++j)
			unite(g[i][0], g[i][j]);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		get(i);
	for (int i = 1; i <= n; ++i) {
		ans += (d[i] == i);
		if (d[i] == i)
			db(i);
	}
	cout << ans - 1;
	return 0;
}
