#include <bits/stdc++.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;
	while (T--) {
		string x, y, w; cin >> x >> y >> w;
		vector<vector<int>> sumX(x.size(), vector<int>('z' + 1)), sumY(y.size(), vector<int>('z' + 1));
		for (int i = 0; i < x.size(); i++) {
			if (i) sumX[i] = sumX[i - 1];
			sumX[i][x[i]]++;
		}
		for (int i = 0; i < y.size(); i++) {
			if (i) sumY[i] = sumY[i - 1];
			sumY[i][y[i]]++;
		}
		vector<int> La(w.size()), Ra(w.size()), Lb(w.size()), Rb(w.size());
		auto solve = [&](string a, auto &vec) {
			int k = 0;
			for (int i = 0; i < w.size(); i++) {
				while (a[k] != w[i]) ++k;
				vec[i] = k++;
			}
		};
		solve(x, La);
		solve(y, Lb);
		reverse(x.begin(), x.end());
		reverse(y.begin(), y.end());
		reverse(w.begin(), w.end());
		solve(x, Ra);
		solve(y, Rb);
		reverse(Ra.begin(), Ra.end());
		reverse(Rb.begin(), Rb.end());
		for (auto &i : Ra) i = x.size() - i - 1;
		for (auto &i : Rb) i = y.size() - i - 1;
		int f = 0;
		auto ssolve = [&](int a, int b, int c, int d) {
			--b, --d;
			if (b < 0 || d < 0) return;
			//if (a + 1 >= b || c + 1 >= d) return;
			//cout << a << " " << b << " " << c << " " << d;
			//return;
			vector<int> U = sumX[b], V = sumY[d];
			if (a >= 0) for (int i = 0; i < sumX[a].size(); i++) U[i] -= sumX[a][i];
			if (c >= 0) for (int i = 0; i < sumY[c].size(); i++) V[i] -= sumY[c][i];
			for (int i = 0; i < U.size(); i++) f |= U[i] && V[i];
			//cout << f << "\n";
		};
		//cout << "E\n";
		ssolve(-1, Ra[0], -1, Rb[0]);
		ssolve(La.back(), x.size(), Lb.back(), y.size());
		for (int i = 0; i < w.size() - 1; i++) ssolve(La[i], Ra[i + 1], Lb[i], Rb[i + 1]);

		//int f = 0;
		//for (char c = 'a'; c <= 'z'; ++c) f |= A[c] && B[c];
		cout << f << "\n";
	}
}
