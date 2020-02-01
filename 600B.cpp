///created: 4/Jun/2019 20:31:29

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

const int N = 2e5 + 1;
int n, m, a[N], b[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= m; ++i)
		cout << (upper_bound(a + 1, a + 1 + n, b[i]) - 1 - a) << ' ';
	return 0;
}
