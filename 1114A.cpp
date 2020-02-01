///created: 28/May/2019 13:19:20

#include <bits/stdc++.h>

using namespace std;

void no() { printf("NO"); exit(0); }

int main() {
	int x, y, z, a, b, c;
	cin >> x >> y >> z;
	cin >> a >> b >> c;
	if (a < x) no();
	a -= x;
	if (a + b < y) no();
	a -= y;
	if (a < 0) { b -= -a; a = 0; }
	if (a + b + c < z) no();
	printf("YES");
	return 0;
}
