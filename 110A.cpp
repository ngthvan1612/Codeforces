#include <bits/stdc++.h>

using namespace std;

int main() {
	typedef long long ll;
	ll n;
	cin >> n;
	int cnt = 0;
	while (n) {
		cnt += (n % 10 == 4 || n % 10 == 7);
		n /= 10;
	}
	if (cnt == 4 || cnt == 7) cout << "YES";
	else cout << "NO";
	return 0;
}

