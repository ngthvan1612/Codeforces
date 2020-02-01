///created: 9/Jun/2019 12:47:29

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

ii a[5001];
int n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + 1 + n);
	int ans = a[1].second;
	for (int i = 2; i <= n; ++i) {
		if (ans <= a[i].second)
			ans = max(ans, a[i].second);
		else
			ans = max(ans, a[i].first);
	}
	cout << ans;
	return 0;
}
