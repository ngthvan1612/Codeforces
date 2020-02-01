///created: 1/Jun/2019 10:50:35

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int n;
	cin >> n;
	n %= 4;
	if (n == 3 || n == 0) cout << 0;
	else cout << 1;
	return 0;
}
