#include <bits/stdc++.h>

using namespace std;

int S(int u) {
	int sum = u;
	do {
		int tmp = 0;
		while (sum) { tmp += sum % 10; sum /= 10; }
		sum = tmp;
	}
	while (sum > 9);
	return sum;
}

int S(string s) {
	int res = 0;
	for (int i = 0; i < int(s.length()); ++i)
		res += s[i] - '0';
	return S(res);
}

int main() {
	int k, d;
	cin >> k >> d;
	if (d == 0 && k > 1) {
		cout << "No solution";
		return 0;
	}
	cout << d;
	for (int i = 1; i < k; ++i)
		cout << '0';
	return 0;
}
