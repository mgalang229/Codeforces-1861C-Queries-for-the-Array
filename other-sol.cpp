#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void test_case(int& tc) {
	string s;
	cin >> s;
	int len = 0, sorted = 0, unsorted = INT_MAX;
	bool good = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+') {
			len++;
		} else if (s[i] == '-') {
			len--;
		} else if (s[i] == '1') {
			sorted = len;
		} else if (s[i] == '0' && unsorted == INT_MAX) {
			unsorted = len;
		}
		if (sorted > len) {
			sorted = len;
		}
		if (len < unsorted) {
			unsorted = INT_MAX;
		}
		if ((s[i] == '0' && len == sorted) || (s[i] == '1' && unsorted <= len) || (s[i] == '0' && len < 2)) {
			good = false;
			break;
		}
	}
	cout << (good ? "YES" : "NO") << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
