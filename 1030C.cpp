///created: 30/Jun/2019 10:49:15

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int modulo = 1e9 + 7;

#ifdef LOCAL_DEBUG_NTV1612
template<class __Ty>
string to_string(__Ty a) {
	string res = "[ ";
	bool f = true;
	for (auto &p : a) { res += (f ? string("") : string(", ")) + to_string(p); f = false;	}
	return res + " ]";
}
void _debug() { fprintf(stderr, "\n"); }
template<typename __Ty_head, typename... __Ty_tail>
void _debug(__Ty_head head, __Ty_tail... tail) { fprintf(stderr, "%s ", to_string(head).c_str()); _debug(tail...); }
#define debug(...) fprintf(stderr, "DEBUG [%s]: ", #__VA_ARGS__), _debug(__VA_ARGS__)
#else
#define debug(...) 0
#endif

template<class __Ty> bool mini(__Ty& a, __Ty b) { return a > b ? ((a = b) | 1) : (0); }
template<class __Ty> bool maxi(__Ty& a, __Ty b) { return a < b ? ((a = b) | 1) : (0); }
template<class __Ty> __Ty add(__Ty a, __Ty b) { return (a + b) % (__Ty(modulo)); }
template<class __Ty> __Ty sub(__Ty a, __Ty b) { __Ty m(modulo); return ((a - b) % m + m) % m; }

const int N = 1e2 + 5;
char a[N];
int n;

bool check(int s) {
	int cnt = 0, i = 1;
	while (i <= n) {
		int sum = a[i] - '0';
		int j = i + 1;
		while (sum <= s && j <= n)
			sum += a[j++] - '0';
		if (sum > s && j > i + 1) {
			sum -= a[j - 1] - '0';
			--j;
		}
		if (sum != s) return false;
		i = j;
		cnt++;
	}
	debug(s, cnt);
	return cnt >= 2;
}

bool check2(int s) {
	queue<int> q;
	for (int i = 1; i <= n; ++i)
		q.push(a[i] - '0');
	int cnt = 0;
	while (!q.empty()) {
		int sum = 0;
		while (!q.empty() && sum + q.front() <= s) {
			sum += q.front();
			q.pop();
		}
		if (sum != s) return 0;
		cnt++;
	}
	return cnt >= 2;
}

int main() {
	///ios::sync_with_stdio(0); cin.tie(0);
	int sum = 0;
	scanf("%d%s", &n, a + 1);
	for (int i = 1; i <= n; ++i)
		sum += a[i] - '0';
	if (sum == 0) {
		cout << "YES";
		return 0;
	}
	for (int i = 1; i <= sum; ++i)
		if (sum % i == 0 && check(i)) {
			debug(i);
			cout << "YES";
			return 0;
		}
	cout << "NO";
	return 0;
}
