#include <bits/stdc++.h>

using namespace std;

int main() {
	int h[2], m[2];
	scanf("%d:%d", &h[0], &m[0]);
	scanf("%d:%d", &h[1], &m[1]);
	int se0 = h[0] * 60 + m[0];
	int se1 = h[1] * 60 + m[1];
	se0 = (se0 + se1) / 2;
	printf("%02d:%02d", se0 / 60, se0 % 60);
	return 0;
}
