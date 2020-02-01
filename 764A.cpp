///created: 1/Jun/2019 15:11:55

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	int n, m, z;
	cin >> n >> m >> z;
	cout << z / (n * m /  __gcd(n, m));
	return 0;
}
