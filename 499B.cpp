///created: 30/May/2019 14:59:17

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<string, string> mp;
	for (int i = 1; i <= m; ++i) {
		string f, s;
		cin >> f >> s;
		if (f.length() > s.length())
			mp[f] = s;
		else
			mp[f] = f;
	}
	for (int i = 1; i <= n; ++i) {
		string c;
		cin >> c;
		cout << mp[c] << ' ';
	}
	return 0;
}
