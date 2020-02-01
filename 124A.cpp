///created: 1/Jun/2019 10:24:42

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int n, a, b, ans = 0;
	cin >> n >> a >> b;
	cout << min(n - (a + 1) + 1, n - (n - b) + 1);
	return 0;
}
