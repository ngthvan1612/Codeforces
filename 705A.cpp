#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, r = 1;
	cin >> n;
	while (n--) {
		if (r) cout << "I hate ";
		else cout << "I love ";
		r ^= 1;
		if (n > 0) cout << "that ";
		else cout << "it";
	}
	return 0;
}
