#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, b = 0;
	typedef long long ll;
	ll sum = 0;
	cin >> n >> sum;
	while (n--) {
		string s;
		int tmp;
		cin >> s >> tmp;
		if (s == "+") sum += tmp;
		else { if (sum < tmp) b++; else sum -= tmp; }
	}
	cout << sum << ' ' << b;
	return 0;

