///created: 31/May/2019 20:33:12

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int n, x, y, cnt10 = 0, sa = 0, sb = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		sa += x, sb += y;
		if ((x + y) % 2) cnt10 = 1;
	}
	if (sa % 2 == 1 && sb % 2 == 1 && cnt10)
		cout << 1;
	else if (sa % 2 == 0 && sb % 2 == 0)
		cout << 0;
	else cout << -1;
	return 0;
}
