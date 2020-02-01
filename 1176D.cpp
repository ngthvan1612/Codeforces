///created: 11/Jun/2019 16:12:42

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';
template<class __Ty> bool minimize(__Ty& a, __Ty b) {
	if (a > b) { a = b; return true; }
	return false;
}
template<class __Ty> bool maximize(__Ty& a, __Ty b) {
	if (a < b) { a = b; return true; }
	return false;
}

const int N = 3e6 + 5;
const int NP = 3e6 + 5;
int n, b[N], ip[NP], pre[NP];
int prime[N], sz_prime = 0;
int cnt[NP] = {0};

void init() {
	ip[0] = ip[1] = 0;
	for (int i = 2; i < NP; ++i) {
		ip[i] = 1;
		pre[i] = -1;
	}
	for (int i = 2; i * i < NP; ++i)
		if (ip[i])
			for (int j = i * i; j < NP; j += i) {
				ip[j] = 0;
				pre[j] = max(pre[j], j / i);
			}
	for (int i = 2; i < NP; ++i)
		if (ip[i]) {
			pre[i] = i;
			prime[++sz_prime] = i;
		}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> b[i];
		cnt[b[i]]++;
	}
	init();
	sort(b + 1, b + 1 + 2 * n);
	reverse(b + 1, b + 1 + 2 * n);
	vector<int> ans;
	for (int i = 1; i <= 2 * n; ++i) 
		if (cnt[b[i]] > 0) {
			if (ip[b[i]]) {
				if (cnt[prime[b[i]]] > 0) {
					ans.push_back(b[i]);
					cnt[b[i]]--;
					cnt[prime[b[i]]]--;
				}
			}
			else {				
				if (cnt[pre[b[i]]] > 0) {
					ans.push_back(b[i]);
					cnt[b[i]]--;
					cnt[pre[b[i]]]--;
				}
			}
		}
	for (int i = 0; i < NP; ++i)
		assert(cnt[i] == 0);
	for (int v : ans)
		cout << v << ' ';
	return 0;
}
