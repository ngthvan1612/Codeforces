#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long ans = 0;
	int i = 1, j = n;
	while (i < j && i + 1 != j) {
		ans = ans + min((j + i + 1) % (n + 1), (i + j - 1) % (n + 1));
		++i;
		--j;
	}
	cout << ans;
	return 0;
}
