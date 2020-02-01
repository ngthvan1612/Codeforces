///created: 1/Jun/2019 20:33:26

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n;
char a[100002], b[100002], dp[100002];

int main() {
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	scanf("%s", a + 1);
	n = int(strlen(a + 1));
	int j = -1, od = -1;
	bool sw = false;
	for (int i = 1; i <= n - 1; ++i)
		if ((a[i] - '0') % 2 == 0) {
			od = i;
			if (j == -1) j = i;
			else if (a[j] >= a[i]) j = i;
			if (a[j] < a[n] && !sw) {
				sw = true;
				swap(a[j], a[n]);
			}
		}
	if (!sw && od != -1) swap(a[od], a[n]), sw = 1;
	printf("%s", sw ? a + 1 : "-1");
	return 0;
}
