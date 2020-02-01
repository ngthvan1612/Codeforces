///created: 21/Jun/2019 18:35:56

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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, a, ans = 1, pre = 1e9 + 7, cur = 1;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (a > pre) cur++;
		else cur = 1;
		pre = a;
		ans = max(ans, cur);
	}
	cout << ans;
	return 0;
}
