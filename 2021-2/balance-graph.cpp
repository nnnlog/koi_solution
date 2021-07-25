// SCORE: 6/100

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	assert(m == 3);
	map<int, map<int, int>> mp;
	while (m--) {
		int a, b, w; cin >> a >> b >> w;
		if (a > b) swap(a, b);
		mp[a][b] = w;
	}
	int X = mp[1][2], Y = mp[2][3], Z = mp[1][3];
	int a = X + Z - Y;
	int b = X + Y - Z;
	int c = Y + Z - X;
	if (a % 2 || b % 2 || c % 2) {
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	cout << a / 2 << " " << b / 2 << " " << c / 2;
}