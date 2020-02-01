#include <bits/stdc++.h>

using namespace std;

int n, a[100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int t25 = 0, t50 = 0, t100 = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 25) t25++;
		else if (a[i] == 50) {
			if (t25) t25--, t50++;
			else {
				cout << "NO";
				return 0;
			}
		}
		else {
			if (t50 && t25) t50--, t25--;
			else if (t25 >= 3) t25 -= 3;
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}
