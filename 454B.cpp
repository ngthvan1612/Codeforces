///created: 31/May/2019 20:10:48

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N =1e5 + 1;
int a[N], n, v = 0;

int main() {
	scanf("%d", &n);
	bool ans = true;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n - 1; ++i) {
		if (a[i] <= a[i + 1]) continue;
		for (int j = i + 1; j <= n - 1; ++j)
			if (a[j] > a[j + 1]) {
				ans &= false;
			}
		if (a[n] > a[1]) ans &= false;
		v = n - i;
		break;
	}
	if (ans) printf("%d", v);
	else printf("-1");
	return 0;
}
