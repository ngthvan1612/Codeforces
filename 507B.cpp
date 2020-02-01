///created: 1/Jun/2019 17:34:43

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	double r, x, y, u, v;
	cin >> r >> x >> y >> u >> v;
	double mr = sqrt((x - u) * (x - u) + (y - v) * (y - v));
	cout << int(ceil(mr / (2 * r)));
	return 0;
}
