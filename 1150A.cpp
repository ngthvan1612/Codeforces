#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, r, nmin = int(1e9), mmax = 0, tmp;
	cin >> n >> m >> r;
	while (n--) { cin >> tmp; nmin = min(nmin, tmp); }
	while (m--) { cin >> tmp; mmax = max(mmax, tmp); }
	int res = r % nmin + r / nmin * mmax;
	cout << max(r, res);
	return 0;
}
