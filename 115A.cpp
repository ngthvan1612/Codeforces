///created: 3/Jun/2019 21:16:47

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

vector<int> g[2001];
bool vs[2001] = {0};

int dfs(int u) {
	vs[u] = 1;
	int res = 1;
	for (int v : g[u])
		res = max(res, dfs(v) + 1);
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int t;
		cin >> t;
		if (t > 0)
			g[t].push_back(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (!vs[i])
			ans = max(ans, dfs(i));
	cout << ans;
	return 0;
}
