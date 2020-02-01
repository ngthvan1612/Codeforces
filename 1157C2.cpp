///created: 1/Jul/2019 19:19:56

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

const int N = 2e5 + 5;
int a[N], n, pre[N], suf[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	vector<int> f;
	string ans;
	f.push_back(-1);
	pre[1] = -1e9;
	suf[n] = +1e9;
	for (int i = 2; i <= n; ++i)
		if (a[i] == a[i - 1])
			pre[i] = i;
		else pre[i] = pre[i - 1];
	for (int i = n - 1; i >= 1; --i)
		if (a[i] == a[i + 1])
			suf[i] = i;
		else suf[i] = suf[i + 1];
	int i = 1, j = n, m;
	while (i <= j) {
		if (max(a[i], a[j]) <= f.back()) break;
		debug(i, j);
		if (a[i] < a[j]) {
			if (a[i] <= f.back()) {
				ans.push_back('R');
				f.push_back(a[j--]);
			}
			else {
				ans.push_back('L');
				f.push_back(a[i++]);
			}
		}
		else if (a[i] > a[j]) {
			if (a[j] <= f.back()) {
				ans.push_back('L');
				f.push_back(a[i++]);
			}
			else {
				ans.push_back('R');
				f.push_back(a[j--]);
			}
		}
		else {
			int kj = j - 1, ki = i + 1;
			char c = 'L';
			while (ki <= j && a[ki - 1] < a[ki])
				ki++;
			while (kj >= i && a[kj + 1] < a[kj])
				kj--;
			if (j - kj > ki - i) c = 'R';
			for (int z = 0; z < max(j - kj, ki - i); ++z)
				ans.push_back(c);
			debug(ki, kj);
			break;
		}
	}
	cout << ans.size() << '\n' << ans;
	return 0;
}
