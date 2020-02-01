///created: 1/Jun/2019 15:05:44

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int n;
	cin >> n;
	if (n % 2) { cout << -1; return 0; }
	for (int i = 1; i <= n; i += 2)
		cout << i + 1 << ' ' << i << ' ';
	return 0;
}
