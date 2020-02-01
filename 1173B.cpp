///created: 8/Jun/2019 19:54:58

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
	int n, l = 1, res = 1;
	cin >> n;
	vector<ii> ans;
	ans.push_back(ii(1, 1));
	for (int i = 1; i <= n - 1; ++i) {
		if (l) ans.push_back(ii(ans[i - 1].first, ans[i - 1].second + 1));
		else ans.push_back(ii(ans[i - 1].first + 1, ans[i - 1].second));
		res = max(res, max(ans[i].first, ans[i].second));
		l ^= 1;
	}
	cout << res << '\n';
	for (int i = 0; i <= n - 1; ++i)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	return 0;
}
