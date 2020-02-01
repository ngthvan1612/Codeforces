///created: 6/Jun/2019 21:50:56

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

int n, k, cnt[256] = {0};
bool cmp(char i, char j) {
	return (cnt[i] > cnt[j]) || (cnt[i] == cnt[j] && i > j);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> n >> k >> s;
	for (char c : s)
		cnt[c]++;
	sort(s.begin(), s.end(), cmp);
	memset(cnt, 0, sizeof cnt);
	ll ans = 0;
	for (int i = 0; i < k; ++i)
		cnt[s[i]]++;
	for (int i = 0; i < 256; ++i)
		ans += 1LL * cnt[i] * cnt[i];
	cout << ans;
	return 0;
}
