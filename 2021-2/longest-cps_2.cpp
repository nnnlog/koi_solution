// SCORE: 17/100 (Subtask 4)

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
		assert(a == b);
		int n = a.size();
		vector<int> vis(n);
		set<int> S;
		for (int i = 0; i < n; i++) S.insert(i);
		auto nxt = [&](int r) {
			auto it = S.lower_bound(r);
			if (it == S.end()) return n;
			return *it;
		};
		auto prv = [&](int l) {
			auto it = S.upper_bound(l);
			if (it == S.begin()) return -1;
			return *--it;
		};
		for (int i = 1; i < n; i++) {
			int l = prv(i - 1), r = nxt(i);
			while (l >= 0 && r < n && a[l] == '(' && a[r] == ')') {
				//cout << l << " " << r << "\n";
				vis[l] = 1;
				vis[r] = 1;
				//cout << i - sz << " " << i + sz + 1 << " ";
				S.erase(l), S.erase(r);
				l = prv(l), r = nxt(r);
			}
			i = nxt(i);
			//cout << "\n";
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) continue;
			int cnt = 0;
			while (i + cnt < n && vis[i + cnt]) ++cnt;
			ans = max(ans, cnt);
			i += cnt;
		}
		cout << ans << "\n";
	}
}
