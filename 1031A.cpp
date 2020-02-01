///created: 1/Jun/2019 13:59:43

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int w, h, k, ans = 0;
	cin >> w >> h >> k;
	while (k--) {
		ans += 2 * w + 2 * h - 4;
		w -= 4;
		h -= 4;
	}
	cout << ans;
	return 0;
}
