///created: 1/Jun/2019 15:28:12

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int t;
	ll s, a, b, c;
	for (cin >> t; t--;) {
		cin >> s >> a >> b >> c;
		cout << s / c + ((s / c) / a) * b << '\n';
	}
	return 0;
}
