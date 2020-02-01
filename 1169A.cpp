///created: 1/Jun/2019 10:19:38

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int n, a, b, x, y;
	cin >> n >> a >> x >> b >> y;
	while (a != x && b != y) {
		if (a != x) {
			a = a + 1;
			if (a > n) a = 1;
		}
		if (b != y) {
			b = b - 1;
			if (b < 1) b = n;
		}
		if (a == b) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
