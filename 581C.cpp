///created: 13/Jul/2019 18:39:29

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

struct CompareHeap {
	bool operator()(int u, int v) {
		return (u % 10 < v % 10) || (u % 10 == v % 10 && u > v);
	}
};

vector<int> toVector(priority_queue<int, vector<int>, CompareHeap > heap) {
	vector<int> v;
	while (!heap.empty()) {
		v.push_back(heap.top());
		heap.pop();
	}
	return v;
}

const int N = 1e5 + 5;
int a[N];

bool cmp(int u, int v) { return u % 10 > v % 10; }

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; ++i) {
		int up = 10 - a[i] % 10;
		if (k >= up && a[i] + up <= 100) {
			k -= up;
			a[i] += up;
		}
	}
	for (int i = 1; i <= n; ++i) {
		int up = min(k, 100 - a[i]);
		k -= up;
		a[i] += up;
	}
	int sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += a[i] / 10;
	cout << sum;
	return 0;
}
