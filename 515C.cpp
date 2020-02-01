///created: 1/Jun/2019 16:45:07

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

ll fact[11], x[1000];

void dfs(int i, ll p, int v) {
	if (p > 1LL * fact[v]) return;
	if (p == 1LL * fact[v]) {
		ll tmp = 1;
		for (int j = 0; j < i; ++j) {
			cout << x[j] << ' ';
			tmp *= fact[x[j]];
		}
		cout << '\n';
		return;
	}
	for (int j = 2; j <= 9; ++j) {
		x[i] = j;
		dfs(i + 1, p * fact[j], v);
	}
}

int main() {
	int n;
	string a, ans;
	cin >> n >> a;
	for (char c : a)
		if (c != '0' && c != '1') {
			if (c == '4') ans += "223";
			else if (c == '6') ans += "53";
			else if (c == '8') ans += "7222";
			else if (c == '9') ans += "7332";
			else ans += c;
		}
	sort(ans.rbegin(), ans.rend());
	cout << ans;
/*
	fact[0] = 1;
	for (int i = 1; i <= 9; ++i)
		fact[i] = i * fact[i - 1];
	dfs(0, 1, 6);
*/	
	return 0;
}
