///created: 21/Jun/2019 18:18:52

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
	int a, b, ans = 0;
	cin >> a >> b;
	while (a > 0 && b > 0) {
		if (a > b) swap(a, b);
		a += 1;
		b -= 2;
		if (a >= 0 && b >= 0)
			ans++;
	}
	cout << ans;
	return 0;
}
