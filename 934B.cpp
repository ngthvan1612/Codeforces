#include <bits/stdc++.h>

using namespace std;

int main() {
	int k;
	cin >> k;
	if (k == 1) { cout << 4; return 0; }
	vector<int> res;
	bool has0 = false;
	while (k) {
		if (k >= 2) {
			res.push_back(8);
			k -= 2;
		}
		else {
			res.push_back(10);
			k -= 1;
		}
	}
	if (int(res.size()) > 18) { cout << -1; return 0; }
	sort(res.begin(), res.end());
	for (int a : res)
		if (a < 10) cout << a;
		else cout << 0;
	return 0;
}
