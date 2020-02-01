#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	int smin = 0, tmp = 0;
	for (char c : s) {
		if (c == '-') tmp--;
		else tmp++;
		smin = min(smin, tmp);
	}
	smin = -smin;
	for (char c : s)
		if (c == '-') smin--;
		else smin++;
	cout << smin;
	return 0;
}
