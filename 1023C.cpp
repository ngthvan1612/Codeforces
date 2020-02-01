#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;
char a[N];
bool vs[N] = {0};
int n, k;

int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", a + 1);
	stack<int> st;
	for (int i = 1; i <= n && k > 0; ++i)
		if (a[i] == '(') st.push(i);
		else {
			vs[st.top()] = 1;
			st.pop();
			vs[i] = 1;
			k -= 2;
		}
	for (int i = 1; i <= n; ++i)
		if (vs[i])
			printf("%c", a[i]);
	return 0;
}	
