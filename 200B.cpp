#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	double sum = 0.00;
	cout << fixed << setprecision(10);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		double t;
		cin >> t;
		sum += t / 100.00;
	}
	cout << sum / (1.0 * n) * 100;
	return 0;
}
