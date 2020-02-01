#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
ii a[1001], b[1001];
int n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	for (int i = 1; i <= n; ++i)
		cin >> b[i].first >> b[i].second;
	map<ii, int> cnt;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cnt[ii(a[i].first + b[j].first, a[i].second + b[j].second)]++;
	for (pair<ii, int> p : cnt)
		if (p.second >= n) {
			cout << p.first.first << ' ' << p.first.second;
			return 0;
		}
	return 0;
