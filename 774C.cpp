///created: 27:04:2019 19:56:20

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 2) {
		n -= 3;
		printf("7");
	}
	for (int i = 1; i <= n / 2; ++i)
		printf("1");
	return 0;
}
