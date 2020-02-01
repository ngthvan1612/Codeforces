///created: 7/Jun/2019 13:51:10

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
	string s, t;
	cin >> n >> s >> t;
	bool hans = true;
	vector<int> ans;
	for (int i = 0; i < n; ++i)
		if (s[i] != t[i]) {
			int j = -1;
			for (int k = i + 1; k < n; ++k)
				if (s[k] == t[i]) {
					j = k;
					break;
				}
			if (j == -1) {
				hans = false;
				break;
			}
			for (int k = j - 1; k >= i; --k) {
				swap(s[k], s[k + 1]);
				ans.push_back(k + 1);
			}
		}
	if (!hans) cout << -1;
	else {
		cerr << "s = " << s << '\n';
		cout << int(ans.size()) << '\n';
		for (int v : ans)
			cout << v << ' ';
	}
	return 0;
}
