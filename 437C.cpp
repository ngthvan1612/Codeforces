///created: 11/Jun/2019 19:13:24

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

int n, m, a[1001], v[1001], mark[1001] = {0}, d[1001] = {0}, id[1001];
vector<int> g[1001];

bool cmp(int i, int j) {
	return v[i] < v[j];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		id[i] = i;
		cin >> v[i];
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		d[u]++;
		d[v]++;
	}
	sort(id + 1, id + 1 + n, cmp);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		mark[id[i]] = 1;
		for (int u : g[id[i]])
			if (!mark[u])
				cnt++;
///		printf("%d del %d (cost = %d)\n", id[i], cnt, cnt * v[id[i]]);
		ans += cnt * v[id[i]];
	}
	cout << ans;
	return 0;
}
