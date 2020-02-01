///created: 5/Jun/2019 19:56:28

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int ExEuclid(int a, int b, int& x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int d = ExEuclid(b, a % b, x, y);
	int tmp = x;
	x = y;
	y = tmp - (a / b) * y;
	return d;
}

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = 0; i <= 100; ++i)
		if ((c * i + d - b >= 0) && (c * i + d - b) % a == 0) {
			cout << c * i + d;
			return 0;
		}
	cout << -1;
	return 0;
}
