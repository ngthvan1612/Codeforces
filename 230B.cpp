///created: 31/May/2019 07:48:02

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
const int M = 1e6 + 1;
int n;
bool ip[M];

int main() {
	ip[0] = ip[1] = 0;
	for (int i = 2; i < M; ++i)
		ip[i] = 1;
	for (int i = 2; i * i < M; ++i)
		if (ip[i])
			for (int j = i * i; j < M; j += i)
				ip[j] = 0;
	for (scanf("%d", &n); n--;) {
		long long a;
		scanf("%I64d", &a);
		int p = int(sqrt(a));
		if (1LL * p * p == a && ip[p] == true)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
