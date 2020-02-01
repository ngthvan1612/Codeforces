#include <bits/stdc++.h>

using namespace std;

void Fill(int n, int* d) {
	for (int i = 0; i < 5; ++i)
		d[i] = n / 5;
	n %= 5;
	for (int i = 1; i <= n; ++i)
		d[i]++;
}

int main() {
	int n, m, cnta[5] = {0}, cntb[5] = {0};
	typedef long long ll;
	ll ans = 0;
	cin >> n >> m;
	Fill(n, cnta);
	Fill(m, cntb);
	for (int j = 0; j < 5; ++j)
		ans += 1LL * cntb[j] * cnta[(5 - j) % 5];
	cout << ans;
	return 0;
}
