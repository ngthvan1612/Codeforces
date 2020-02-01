///created: 28/May/2019 15:14:12

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k, w[26], wmax = 0;
	string s;
	cin >> s >> k;
	for (int i = 0; i < 26; ++i) {
		cin >> w[i];
		wmax = max(wmax, w[i]);
	}
	int ans = 0;
	for (int i = 0; i < int(s.length()); ++i)
		ans += w[s[i] - 'a'] * (i + 1);
	cout << ans + ((s.length()) * k + k * (k + 1) / 2)* wmax;
	return 0;
}
