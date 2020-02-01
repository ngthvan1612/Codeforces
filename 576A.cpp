///created: 10/Jun/2019 21:30:35

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
	int n;
	vector<int> ans;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		bool testok = 1;
		for (int j = 2; j * j <= i; ++j)
			if (i % j == 0)
				testok = 0;
		if (testok)
			for (int j = i; j <= n; j *= i)
				ans.push_back(j);
	}
	cout << ans.size() << '\n';
	for (int v : ans)
		cout << v << ' ';
	return 0;
}
