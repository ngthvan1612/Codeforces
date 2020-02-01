///created: 1/Jun/2019 13:43:29

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int a, b, c, ans = 1e9 + 7;
	cin >> a >> b >> c;
	if (a + b <= c) { ans = min(ans, c - (a + b) + 1); }
	if (a + c <= b) { ans = min(ans, b - (a + c) + 1); }
	if (b + c <= a) { ans = min(ans, a - (b + c) + 1); }
	cout << (ans == 1e9 + 7 ? 0 : ans);
	return 0;
}
