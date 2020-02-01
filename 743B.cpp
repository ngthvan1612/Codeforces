#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int Find(ll l, ll r, ll kth, int ans) {
	ll mid = (l + r) / 2;
	if (kth < mid) return Find(l, mid - 1, kth, ans - 1);
	else if (kth > mid) return Find(mid + 1, r, kth, ans - 1);
	return ans;
}

int FindBs(ll l, ll r, ll kth, int ans) {
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (kth < mid) { r = mid - 1; }
		else if (kth > mid) { l = mid + 1; }
		else return ans;
		ans--;
	}
}

int main() {
	ll n, k;
	cin >> n >> k;
	ll right = 1, left = 1;
	for (int i = 1; i < n; ++i)
		right = right * 2LL + 1LL;
	cout << FindBs(left, right, k, n);
	return 0;
}	
