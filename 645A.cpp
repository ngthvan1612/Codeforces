///created: 27:04:2019 19:40:17

#include <bits/stdc++.h>

using namespace std;

string a[2], b[2];

bool dfs(int u);

bool dfs(int u) {
	if (a[0] == b[0] && b[1] == a[1]) return true;
	if (u > 10) return false;
	bool ans = false;
	if (a[0][0] == 'X') {
		swap(a[0][0], a[1][0]);
		ans |= dfs(u + 1);
		swap(a[0][0], a[1][0]);
		swap(a[0][0], a[0][1]);
		ans |= dfs(u + 1);
		swap(a[0][0], a[0][1]);
	}
	if (a[0][1] == 'X') {
		swap(a[0][1], a[1][1]);
		ans |= dfs(u + 1);
		swap(a[0][1], a[1][1]);
		swap(a[0][1], a[0][0]);
		ans |= dfs(u + 1);
		swap(a[0][1], a[0][0]);
	}
	if (a[1][0] == 'X') {
		swap(a[1][0], a[0][0]);
		ans |= dfs(u + 1);
		swap(a[1][0], a[0][0]);
		swap(a[1][0], a[1][1]);
		ans |= dfs(u + 1);
		swap(a[1][0], a[1][1]);
	}
	if (a[1][1] == 'X') {
		swap(a[1][1], a[1][0]);
		ans |= dfs(u + 1);
		swap(a[1][1], a[1][0]);
		swap(a[1][1], a[0][1]);
		ans |= dfs(u + 1);
		swap(a[1][1], a[0][1]);
	}
	return ans;
}

int main() {
	cin >> a[0] >> a[1];
	cin >> b[0] >> b[1];
	cout << (dfs(0) ? "YES" : "NO");
	return 0;
}
