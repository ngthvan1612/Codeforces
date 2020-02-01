///created: 27:04:2019 19:12:32

#include <bits/stdc++.h>

using namespace std;

const char* a = "ROYGBIV";

int main() {
	int n;
	cin >> n;
	n -= 7;
	printf("%s", a);
	for (int i = 0; i < n; ++i)
		printf("%c", a[i % 4 + 3]);
	return 0;
}
