// SCORE: 20/100

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
int main() {
	int T; cin >> T;
	int mod = 1e9 + 7;
	while (T--) {
		int a, b; cin >> a >> b;
		int s = max(a, b);
		vector<vl> dp(s + 1, vl(s + 1));
		for (int i = 0; i <= b; i++) dp[0][i] = 1;
		for (int i = 0; i <= a; i++) dp[i][0] = 1;
		ll ans = 0;
		for (int k = 1; k <= s; k++) {
			ll curr = 0;
			vector<vl> nxt(s + 1, vl(s + 1));
			for (int i = 0; i <= a; i++) {
				for (int j = 0; j <= b; j++) {
					nxt[i][j] = 0;
					if (i >= k) nxt[i][j] += dp[i - k][j];
					if (j >= k) nxt[i][j] += dp[i][j - k];
					nxt[i][j] %= mod;
					if (i) nxt[i][j] = max(nxt[i][j], nxt[i - 1][j]);
					if (j) nxt[i][j] = max(nxt[i][j], nxt[i][j - 1]);
					curr = max(curr, nxt[i][j]);
				}
			}
			ans += curr;
			nxt.swap(dp);
			/*
			cout << k << ": \n";
			for (int i = 0; i <= a; i++) {
				for (int j = 0; j <= b; j++) cout << dp[i][j] << " ";
				cout << "\n";
			}*/
		}
		cout << ans << "\n";
	}
}
