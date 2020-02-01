///created: 30/May/2019 14:20:48

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) {
		char c;
		cin >> c;
		if (c == 'C' || c == 'M' || c == 'Y') ans = 1;
	}
	printf(ans ? "#Color" : "#Black&White");
	return 0;
}
