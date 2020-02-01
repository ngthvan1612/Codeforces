///created: 4/Jun/2019 12:39:36

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int n, a[100005], ip[100005];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ip[0] = ip[1] = 0;
	cin >> n;
	for (int i = 2; i <= n; ++i) ip[i] = 1;
	int le = 0;
	for (int i = 2; i <= n; ++i)
		if (ip[i]) {
			a[i] = ++le;
			if (1LL * i * i <= 1LL * n)
				for (int j = i * i; j <= n; j += i) {
					a[j] = a[i];
					ip[j] = 0;
				}
		}
	for (int i = 2; i <= n; ++i)
		cout << a[i] << ' ';
	return 0;
}
