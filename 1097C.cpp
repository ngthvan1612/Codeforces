#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int oo = 1e9 + 7;
const int N = 1e5 + 1;
int n;

struct state {
	int m = 0, e = 0;
	string save;
	state(int a = 0, int b = 0) { m = a; e = b; }
} w[N];
inline bool leq(int a1, int b1, int a2, int b2) { return (a1 > a2) || (a1 == a2 && b1 > b2); }
bool operator>(const state& L, const state& R) { return leq(L.e, L.m, R.e, R.m); }

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	string s;
	getline(cin, s);
	for (int i = 1; i <= n; ++i) {
		getline(cin, s);
		w[i] = state(0, 0);
		for (int j = 0; j < int(s.length()); ++j) {
			if (s[j] == '(') w[i].e++;
			if (s[j] == ')') w[i].e--;
			if (i == 0) w[i].m = w[i].e;
			else w[i].m = min(w[i].m, w[i].e);
		}
		w[i].save = s;
	}
	sort(w + 1, w + 1 + n, greater<state>());
//	for (int i = 1; i <= n; ++i)
//		fprintf(stderr, "[min = %d, end = %d, save = '%s']\n", w[i].m, w[i].e, w[i].save.c_str());
	int i = 1, j = n, res = 0;
	while (i < j) {
		if (w[i].e + w[j].e != 0) {
			if (abs(w[i].e) > abs(w[j].e)) i++;
			else j--;
			continue;
		}
		///w[i].e + w[j].e = 0
		if (w[i].m < 0) { i++; continue; }
		///w[i].m >= 0
		if (w[i].e + w[j].m < 0) { j--; continue; }
		///w[i].e + w[j].m >= 0;
//		fprintf(stderr, "CHOOSE: [start = '%s', end = '%s']\n", w[i].save.c_str(), w[j].save.c_str());
		i++, j--;
		res++;
	}
	cout << res;
	return 0;
}
