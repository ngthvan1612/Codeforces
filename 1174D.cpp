///created: 7/Jun/2019 22:01:25

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

int n, x;
bool vs[(1 << 19) + 1] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> x;
	vs[0] = vs[x] = 1;
	vector<int> ans;
	ans.push_back(0);
	for (int i = 1; i < (1 << n); ++i)
		if (!vs[i]) {
			ans.push_back(i);
			vs[i ^ x] = 1;
		}
	cout << int(ans.size()) - 1 << '\n';
	for (int i = 1; i < int(ans.size()); ++i)
		cout << (ans[i - 1] ^ ans[i]) << ' ';
	return 0;
}
