///created: 1/Jun/2019 15:37:45

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int vs[20000] = {0};

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	queue<int> Q;
	Q.push(n);
	while (!Q.empty() && !vs[m]) {
		int t = Q.front(); Q.pop();
		if (t > 1 && !vs[t - 1]) Q.push(t - 1), vs[t - 1] = vs[t] + 1;
		if (t * 2 <= int(2e4)) Q.push(t * 2), vs[t * 2] = vs[t] + 1;
	}
	cout << vs[m];
	return 0;
}
