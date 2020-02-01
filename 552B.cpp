///created: 31/May/2019 19:23:02

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	long long ans = 0, n, p = 1;
	int digit;
	cin >> n;
	digit = int(log10(n)) + 1;
	for (int i = 1; i < digit; ++i) {
		ans += i * (p * 10 - p);
		p *= 10;
	}
	ans += digit * (n - p + 1);
	cout << ans;
	return 0;
}
