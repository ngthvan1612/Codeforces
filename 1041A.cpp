///created: 28/May/2019 13:30:31

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, amax = -1e9, amin = +1e9, a;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		amax = max(amax, a);
		amin = min(amin, a);
	}
	cout << amax - amin - n + 1;
	return 0;
}
