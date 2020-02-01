#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	map<int, int> mp;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		mp[tmp]++;
		if (mp[tmp] > 2) {
			cout << "NO";
			return 0;
		}
	}
	vector<int> inc, dec;
	for (pair<int, int> p : mp) {
		inc.push_back(p.first);
		if (p.second > 1)
			dec.push_back(p.first);
	}
	cout << "YES\n";
	cout << inc.size() << '\n';
	for (int v : inc)
		cout << v << ' ';
	sort(dec.begin(), dec.end(), greater<int>());
	cout << '\n' << dec.size() << '\n';
	for (int v : dec)
		cout << v << ' ';
	return 0;
}
