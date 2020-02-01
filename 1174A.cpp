///created: 4/Jun/2019 12:23:27

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, a[2001];
	cin >> n;
	for (int i = 1; i <= 2 * n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + 2 * n);
	if (a[1] == a[2 * n]) cout << -1;
	else
		for (int i = 1; i <= 2 * n; ++i)
			cout << a[i] << ' ';
	return 0;
}
