#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, k, cur;
map<int, bool> inq;
map<int, int> key;
typedef pair<int, int> ii;
queue<ii> q;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	cur = 0;
	for (int i = 1; i <= n; ++i) {
		int id;
		cin >> id;
		if (!inq[id]) {
			if (cur < k) {
				key[id]++;
				inq[id] = true;
				q.push(ii(id, key[id]));
				cur++;
			}
			else {
				while (!q.empty() && (q.front().second != key[q.front().first]))
					q.pop();
				if (!q.empty()) {
					inq[q.front().first] = false;
					q.pop();
					inq[id] = true;
					key[id]++;
					q.push(ii(id, key[id]));
				}
			}
		}
	}
	vector<int> res;
	while (!q.empty()) {
		if (q.front().second == key[q.front().first])
			res.push_back(q.front().first);
		q.pop();
	}
	reverse(res.begin(), res.end());
	cout << res.size() << '\n';
	for (const int& v : res)
		cout << v << ' ';
	return 0;
}
