#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, cnt[256] = {0};
	string a;
	cin >> n >> a;
	if (n > 26) cout << -1;
	else {
		for (char c : a) cnt[c]++;
		int res = 0;
		for (int i = 0; i < 256; ++i)
			res += max(0, cnt[i] - 1);
		cout << res;
	}
	return 0;
}
