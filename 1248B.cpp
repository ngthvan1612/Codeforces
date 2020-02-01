#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
int n, a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	typedef long long ll;
	ll suml = 0, sumr = 0;
	for (int i = 1; i <= n; ++i)
		if (i <= n / 2)
			suml += a[i];
		else
			sumr += a[i];
	cout << suml * suml + sumr * sumr;
	return 0;
}
