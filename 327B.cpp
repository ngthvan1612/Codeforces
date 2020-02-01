///created: 4/Jun/2019 20:41:26

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int n, ip[10000001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = int(1e7) - n + 1; i <= int(1e7); ++i)
		printf("%d ", i);
	return 0;
}
