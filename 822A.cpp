///created: 1/Jun/2019 14:41:25

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int a, b, ans = 1;
	cin >> a >> b;
	a = min(a, b);
	for (int i = 1; i <= a; ++i)
		ans *= i;
	cout << ans;
	return 0;
}
