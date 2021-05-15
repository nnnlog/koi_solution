//SCORE : 27/100

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, k; cin >> n >> k;
	priority_queue<pair<ll, char>, vector<pair<ll, char>>, greater<>> pq;
	for (char c = 'A'; c <= 'D'; ++c) {
		int a; cin >> a;
		pq.push({a, c});
	}
	vector<vector<ll>> vec('E');
	while (n--) {
		char c; cin >> c;
		int a; cin >> a;
		vec[c].push_back(a);
	}
	for (auto &v : vec) sort(v.begin(), v.end());
	vector<pair<char, ll>> ans;
	while (k--) {
		auto top = pq.top(); pq.pop();
		if (vec[top.second].empty()) {
			++k;
			continue;
		}
		ans.emplace_back(top.second, vec[top.second].back());
		top.first += vec[top.second].back();
		vec[top.second].pop_back();
		pq.push(top);
	}
	for (const auto &[c, a] : ans) cout << c << " " << a << "\n";
}

