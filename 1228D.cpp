#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;
int n, m, ans[N];
vector<int> g[N];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	set<ll> st;
	map<ll, int > mp;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		ll key = 0;
		if (g[i].size() < 2) {
			cout << -1;
			return 0;
		}
		sort(g[i].begin(), g[i].end());
		for (int v : g[i])
			key = (key * 311 + v + 100003) % mod;
		st.insert(key);
		if (mp[key] == 0) {
			cnt++;
			mp[key] = cnt;
		}
		ans[i] = mp[key];
	}
	if (st.size() != 3) cout << -1;
	else {
		for (int i = 1; i <= n; ++i)
			cout << ans[i] << ' ';
	}
	return 0;
}
