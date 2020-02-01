#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define ms(_mem, _value) memset((_mem), (_value), sizeof(_mem))
typedef long long ll;
typedef pair<int, int> ii;

int __solve() {
	int n, m;
	cin >> n >> m;
	cout << n + (n - 1) / (m - 1);
	return 0;
}

int main(int argc, char** argv) {
	FAST_IO;
	if (argc > 1)
		assert(freopen(argv[1], "r", stdin));
	if (argc > 2)
		assert(freopen(argv[2], "w", stdout));
	int ___res = __solve();
	cerr << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << "\nResult: " << ___res;
	return 0;
}
