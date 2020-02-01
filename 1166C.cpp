#include <bits/stdc++.h>

using namespace std;

int n, a[1000001];
typedef long long ll;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), a[i] = abs(a[i]);
	sort(a + 1, a + 1 + n);
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i - 1, found = i;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (2 * a[mid] >= a[i]) { found = mid; r = mid - 1; }
			else l = mid + 1;
		}
		res += i - found;
	}
	cout << res;
	return 0;
}
