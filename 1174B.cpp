///created: 4/Jun/2019 12:30:14

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int n, a[100005], has_odd = 0, has_even = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] % 2 == 0) has_even = 1;
		else has_odd = 1;
	}
	if (has_odd && has_even)
		sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	return 0;
}
