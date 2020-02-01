///created: 6/Jun/2019 16:04:53

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

int n, c, ans = 0, cur = 0;
char op;
bool in[1000001] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (cin >> n; n--;) {
		cin >> op >> c;
		if (op == '+') {
			in[c] = 1;
			cur++;
		}
		else {
			if (!in[c]) ans++;
			else {
				cur--;
				in[c] = 0;
			}
		}
		ans = max(ans, cur);
	}
	cout << ans;
	return 0;
}
