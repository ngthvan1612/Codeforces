#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n <= 2) { cout << "No"; return 0; }
	printf("Yes\n%d ", n / 2);
	long long s1 = 0, s2 = 0;
	for (int i = 1; i <= n; ++i)
		if (i % 2 == 0)
			printf("%d ", i), s1 += i;
	printf("\n%d ", n - n / 2);
	for (int i = 1; i <= n; ++i)
		if (i % 2 != 0)
			printf("%d ", i), s2 += i;
	printf("\n");	
	fprintf(stderr, "gcd = %lld", __gcd(s1, s2));
	return 0;
}
