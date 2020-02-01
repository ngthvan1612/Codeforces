///created: 1/Jun/2019 14:50:15

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int a, b, c, r;
	cin >> a >> b >> c;
	r = min(a, min(b / 2, c / 4));
	cout << r * 7;
	return 0;
}
