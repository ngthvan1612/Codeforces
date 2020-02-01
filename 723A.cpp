///created: 1/Jun/2019 14:35:24

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int x[3];
	for (int i = 0; i < 3; ++i) cin >> x[i];
	sort(x, x + 3);
	cout << x[2] - x[0];
	return 0;
}
