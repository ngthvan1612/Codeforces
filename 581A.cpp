///created: 1/Jun/2019 09:37:02

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int a, b, c;
	cin >> a >> b;
	c = min(a, b);
	cout << c << ' ';
	a -= c;
	b -= c;
	cout << a / 2 + b / 2;
	return 0;
}
