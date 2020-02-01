///created: 1/Jun/2019 09:27:57

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int x[4];
	cin >> x[0] >> x[1] >> x[2] >> x[3];
	sort(x, x + 4);
	cout << x[3] - x[0] << ' ' << x[3] - x[1] << ' ' << x[3] - x[2];
	return 0;
}
