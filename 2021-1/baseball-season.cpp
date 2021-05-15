#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int T; cin >> T;
	while (T--) {
		ll n, m, k, d; cin >> n >> m >> k >> d;
		ll l = 0, r = 1e9;
		auto solve = [&](ll B) {
			ll A = k * B;
			ll cnt = m * (m - 1) / 2 * A * n;
			cnt += n * (n - 1) / 2 * m * m * B;
			return cnt;
		};
		while (l < r) {
			ll B = (l + r) >> 1;
			if (solve(B) > d) r = B - 1;
			else if (l == B) break;
			else l = B;
		}
		ll B = (l + r) >> 1;
		if (solve(B + 1) <= d) ++B;
		if (solve(B) > d) --B;
		if (B <= 0) cout << -1;
		else {
			cout << solve(B);
		}
		cout << "\n";
	}
}
