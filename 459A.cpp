///created: 31/May/2019 15:17:09

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2) cout << x1 + y2 - y1 << ' ' << y1 << ' ' << x2 + y2 - y1 << ' ' << y2;
	else if (y1 == y2) cout << x1 << ' ' << y1 + x2 - x1 << ' ' << x2 << ' ' << y2 + x2 - x1;
	else if (abs(x2 - x1) == abs(y2 - y1)) cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1;
	else cout << -1;
	return 0;
}
