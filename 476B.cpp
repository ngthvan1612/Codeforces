///created: 1/Jun/2019 16:30:28

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define bp __builtin_popcount

int main() {
	string a, b;
	cin >> a >> b;
	int n = int(a.length()), sl = 0, ta = 0, tb = 0, cnt = 0;
	for (char c : a)
		ta += (c == '+' ? 1 : -1);
	for (char c : b)
		if (c == '+')
			tb++;
		else if (c == '-')
			tb--;
		else
			sl++;
	for (int i = 0; i < (1 << sl); ++i)
		if (tb + 1 * bp(i) - 1 * (sl - bp(i)) == ta)
			cnt++;
	if (ta == tb && sl == 0) cout << 1;
	else {
		int sm = (1 << sl);
		printf("%.15f", 1.0 * cnt / sm);
	}
	return 0;
}
