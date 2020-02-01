///created: 21/Jun/2019 17:17:22

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

const int N = 1.5e5 + 5;
int n, k, f[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	f[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> f[i];
		f[i] += f[i - 1];
	}
	int res = 1e9 + 7, pos = -1;
	for (int i = k; i <= n; ++i)
		if (minimize(res, f[i] - f[i - k]))
			pos = i - k + 1;
	cout << pos;
	return 0;
}
