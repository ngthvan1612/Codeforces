///created: 11/Jun/2019 14:00:17

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

const int ar[] = { 4, 8, 15, 16, 23, 42 };
int n, a[500005], rev[43];
int q[43] = {0};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i < 6; ++i)
		rev[ar[i]] = ar[i - 1];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] > 4) {
			if (q[rev[a[i]]] > 0) {
				--q[rev[a[i]]];
				q[a[i]]++;
			}
		}
		else
			q[4]++;
	}
	cout << n - q[42] * 6;
	return 0;
}
