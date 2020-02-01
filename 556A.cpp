#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int z0 = 0, z1 = 0;
	for (char c : s)
		if (c == '1') z1++;
		else z0++;
	cout << abs(z0 - z1);
	return 0;
