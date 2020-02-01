///created: 21/Jun/2019 17:23:49

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
	///ios::sync_with_stdio(0); cin.tie(0);
	int n, v = 4, ans = 0;
	const int a[] = { 1, 5, 10, 20, 100 };
	cin >> n;
	while (n > 0) {
		if (n < a[v]) v--;
		else {
			int p = n % a[v];
			ans += n / a[v];
			n = p;
		}
	}
	cout << ans;
	return 0;
}
