///created: 7/Jun/2019 20:11:56

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

int n, d[200005], k, cnt[101] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
		d[i] %= k;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int l = (k - d[i]) % k;
		if (cnt[l] > 0) {
			ans += 2;
			cnt[l]--;
		}
		else
			cnt[d[i]]++;
	}
	cout << ans;
	return 0;
}
