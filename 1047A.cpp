///created: 1/Jun/2019 15:16:41

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int n;
	cin >> n;
	if ((n - 2) % 3 == 0) cout << "1 2 " << n - 3 << '\n';
	else cout << "1 1 " << n - 2;
	return 0;
}
