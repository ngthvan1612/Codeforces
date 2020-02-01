///created: 1/Jun/2019 09:42:56

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n, ip[100001] = {0};

int main() {
	cin >> n;
	if (n % 2) {
		n -= 3;
		printf("%d\n%d ", n / 2 + 1, 3);
	}
	else printf("%d\n", n / 2);
	for (int i = 0; i < n / 2; ++i)
		printf("%d ", 2);
	return 0;
}
