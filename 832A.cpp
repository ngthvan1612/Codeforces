///created: 1/Jun/2019 14:44:37

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	ll n, k;
	cin >> n >> k;
	if ((n / k) % 2) cout << "YES";
	else cout << "NO";
	return 0;
}
