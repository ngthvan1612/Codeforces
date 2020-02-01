///created: 1/Jun/2019 13:37:15

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int t, x;
	for (cin>> t; t--;) {
		cin >> x;
		cout << x / 7 + (x % 7 != 0) << '\n';
	}
	return 0;
}
