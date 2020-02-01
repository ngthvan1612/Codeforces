#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, c = 0;
	cin >> n;
	while (n--) {
		printf("%c", c + 'a');
		c = (c + 1) % 4;
	}
	return 0;
}
