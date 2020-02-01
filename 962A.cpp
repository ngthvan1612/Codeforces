///created: 31/May/2019 20:27:02

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n, a[200001], sum = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int p = 0;
	for (int i = 1; i <= n; ++i) {
		p += a[i];
		if (p * 2 >= sum) {
			printf("%d", i);
			return 0;
		}
	}
	return 0;
}
