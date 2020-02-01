///created: 9/Jun/2019 09:20:13

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';
template<class __Ty> bool minimize(__Ty& a, __Ty b) {
	if (a > b) { a = b; return true; }
	return false;
}
template<class __Ty> bool maximize(__Ty& a, __Ty b) {
	if (a < b) { a = b; return true; }
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string a;
	cin >> a;
	int n = int(a.length());
	int cnt = 0;

	for (int i = 0; i < n - 1; ++i)
		if (a[i] == 'A' && a[i + 1] == 'B') {
			for (int j = i + 2; j < n - 1; ++j)
				if (a[j] == 'B' && a[j + 1] == 'A') {
					cout << "YES";
					return 0;
				}
			cnt++;
			if (cnt == 2) break;
		}
		else if (a[i] == 'B' && a[i + 1] == 'A') {
			for (int j = i + 2; j < n - 1; ++j)
				if (a[j] == 'A' && a[j + 1] == 'B') {
					cout << "YES";
					return 0;
				}
			cnt++;
			if (cnt == 2) break;
		}
	cout << "NO";
	return 0;
}
