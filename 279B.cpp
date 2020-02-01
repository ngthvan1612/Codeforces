///created: 20/Jun/2019 10:56:47

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

const int N = 1e5 + 5;
int t, a[N], n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%d", &n, &t);
	a[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, i - (lower_bound(a, a + i, a[i] - t) - a) + 1 - 1);
	}
	printf("%d\n", ans);
	return 0;
}
