///created: 1/Jul/2019 10:00:46

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int modulo = 1e9 + 7;

#ifdef LOCAL_DEBUG_NTV1612
string to_string(string s) { return "'" + s + "'"; }
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

int compare(const vector<int>& a, const vector<int>& b) {
	int m = int(min(a.size(), b.size()));
	for (int i = 0; i < m; ++i)
		if (a[i] > b[i])
			return +1;
		else
			if (a[i] < b[i])
				return -1;
	if (a.size() > b.size()) return +1;
	if (a.size() < b.size()) return -1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int last = 0, n;
	ll sumf = 0, sums = 0;
	vector<int> f, s;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> last;
		if (last > 0) {
			sumf += last;
			f.push_back(last);
		}
		else {
			sums -= last;
			s.push_back(-last);
		}
	}
	int res = compare(f, s);
	if (sumf > sums) cout << "first";
	else if (sumf < sums) cout << "second";
	else if (res == +1) cout << "first";
	else if (res == -1) cout << "second";
	else if (last > 0) cout << "first";
	else cout << "second";
	return 0;
}
