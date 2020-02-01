///created: 7/Jun/2019 14:48:30

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';
template<class __Ty> bool minimize(__Ty& a, __Ty b) {
	if (a > b) { a = b; return true; }
	return false;
}
template<class __Ty> bool maximize(__Ty& a, __Ty b) {
	if (a < b) { a = b; return true; }
	return false;
}

const int N = 1e6 + 4;
int n, m, k;
bool h[N] = {0}, x[N] = {0};


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int tmp;
		cin >> tmp;
		h[tmp] = 1;
	}
	if (h[1]) {
		cout << 1;
		return 0;
	}
	x[1] = 1;
	while (k--) {
		int u, v;
		cin >> u >> v;
		if (x[u] || x[v]) {
			x[u] ^= 1;
			x[v] ^= 1;
			if (h[u] && x[u]) {
				cout << u;
				return 0;
			}
			if (h[v] && x[v]) {
				cout << v;
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		if (x[i])
			cout << i << ' ';
	return 0;
}
