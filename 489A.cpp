///created: 1/Jul/2019 18:22:05

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

int a[3005], n, k;
vector<ii> f;

void QuickSort(int l, int r) {
	if (l < r) {
		int key = a[rand() % (r - l + 1) + l];
		int i = l, j = r;
		while (i <= j) {
			while (a[i] < key) ++i;
			while (a[j] > key) --j;
			if (i <= j) {
				if (a[i] != a[j]) {
					swap(a[i], a[j]);
					f.push_back(ii(i, j));
				}
				++i;
				--j;
			}
		}
		if (l < j) QuickSort(l, j);
		if (i < r) QuickSort(i, r);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		int p = i;
		for (int j = i + 1; j <= n; ++j)
			if (a[p] > a[j])
				p = j;
		if (a[p] != a[i]) {
			f.push_back(ii(i - 1, p - 1));
			swap(a[p], a[i]);
		}
	}
	cout << f.size() << '\n';
	for (ii p : f)
		cout << p.first << ' ' << p.second << '\n';
	return 0;
}
