///created: 4/Jun/2019 21:35:00

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

const int N = 1e3 + 3;
int n, m;
bool a[N] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		a[u] = a[v] = 1;
	}
	for (int i = 1; i <= n; ++i)
		if (!a[i]) {
			cout << n - 1 << '\n';
			for (int j = 1; j <= n; ++j)
				if (i != j)
					cout << i << ' ' << j << '\n';
			break;
		}
	return 0;
}
