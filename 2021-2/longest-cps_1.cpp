// SCORE: 35/100 (Subtask 1, 2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		string a, b; cin >> a >> b;
		int n = a.size(), m = b.size();
		//int l = 0, r = min(n, m) / 2;
		auto valid = [](string s) {
			int cnt = 0;
			for (const auto &c : s) {
				if (c == '(') ++cnt;
				else if (!cnt) return 0;
				else --cnt;
			}
			return cnt == 0 ? 1 : 0;
		};
		auto solve = [&](int mid) {
			for (int i = 0; i + mid - 1 < n; i++) {
				string s = a.substr(i, mid);
				//cout << mid << " " << i << " " << s << "\n";
				if (!valid(s)) continue;
				int t = b.find(s);
				if (t != string::npos) return 1;
			}
			return 0;
		};
		/*
		while (l < r) {
			int mid = (l + r) >> 1;
			if (!solve(mid * 2)) r = mid - 1;
			else if (l == mid) break;
			else l = mid;
		}
		int mid = (l + r) >> 1;
		while (solve(mid * 2)) ++mid;
		cout << (--mid) * 2 << "\n";*/
		for (int i = min(n, m); i >= 0; --i) 
			if (solve(i)) {
				cout << i << "\n";
				break;
			}
	}
}
