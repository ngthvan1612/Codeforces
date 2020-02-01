///created: 21/Jun/2019 17:07:40

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
int a[N], f[N], n, q, cnt[N] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	f[n + 1] = 0;	
	for (int i = n; i >= 1; --i) {
		cnt[a[i]]++;
		f[i] = f[i + 1] + (cnt[a[i]] == 1);
	}
	int x;
	while (q--) {
		cin >> x;
		cout << f[x] << '\n';
	}
	return 0;
}
