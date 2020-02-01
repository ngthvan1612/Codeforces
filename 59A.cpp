#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int lo = 0, up = 0;
	for (char c : s)
		if ('a' <= c && c <= 'z') lo++;
		else up++;
	if (lo >= up) {
		for (char &c : s)
			if ('A' <= c && c <= 'Z')
				c += 32;
	}
	else if (lo < up) {
		for (char &c : s)
			if ('a' <= c && c <= 'z')
				c -= 32;		
	}
	cout << s;
	return 0;
}

