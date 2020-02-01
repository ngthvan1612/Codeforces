#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	int n;
	cin >> n >> s;
	int a = 0, d = 0;
	for (char c : s)
		if (c == 'A') a++;
		else d++;
	if (a > d) cout << "Anton";
	else if (a < d) cout << "Danik";
	else cout << "Friendship";
	return 0;
}

