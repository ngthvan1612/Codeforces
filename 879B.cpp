///created: 6/Jun/2019 18:00:38

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
	int n, a[501], mz = 0;
	ll k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mz = max(mz, a[i]);
	}
	if (k >= n - 1) cout << mz;
	else {
		deque<int> q;
		for (int i = 1; i <= n; ++i)
			q.push_back(a[i]);
		int cur = 0;
		while (true) {
			int t1 = q.front(); q.pop_front();
			int t2 = q.front(); q.pop_front();
			if (t1 > t2) {
				cur++;
				q.push_back(t2);
				q.push_front(t1);
			}
			else {
				cur = 1;
				q.push_back(t1);
				q.push_front(t2);
			}
			if (cur == k) {
				cout << t1;
				return 0;
			}
		}
	}
	return 0;
}
