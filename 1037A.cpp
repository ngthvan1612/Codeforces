///created: 5/Jun/2019 18:55:38

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	int n, ans = 0;
	cin >> n;
	while (n) {
		n >>= 1;
		ans++;
	}
	cout << ans;
	return 0;
}
