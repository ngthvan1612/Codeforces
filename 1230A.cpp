#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[4];

int main() {
	int sum = 0;
	for (int i = 0; i < 4; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + 4);
	if (sum % 2) cout << "NO";
	else {
		if (a[3] == sum / 2) {
			cout << "YES\n";
			return 0;
		}
		for (int i = 1; i < 4; ++i)
			if (a[0] + a[i] == sum / 2) {
				cout << "YES";
				return 0;
			}
		cout << "NO";
	}
	return 0;
}
