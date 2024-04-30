#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void test_case(int& tc) {
	string s;
	cin >> s;
	int max_sorted_pref = 0;
	int min_not_sorted_pref = 0;
	int bal = 0;
	bool good = true;
	for (char& c : s) {
		if (c == '+') {
			++bal;
		} else if (c == '-') {
			--bal;
			max_sorted_pref = min(max_sorted_pref, bal);
			if (bal < min_not_sorted_pref) {
				min_not_sorted_pref = 0;
			}
		} else if (c == '1') {
			max_sorted_pref = max(max_sorted_pref, bal);
		} else {
			if (bal <= 1) {
				good = false;
				break;
			}
			if (min_not_sorted_pref == 0 || min_not_sorted_pref > bal) {
				min_not_sorted_pref = bal;
			}
		}
		if (min_not_sorted_pref <= max_sorted_pref && min_not_sorted_pref != 0) {
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
