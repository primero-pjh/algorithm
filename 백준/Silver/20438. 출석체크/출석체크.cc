#include <iostream>
#include <set>

using namespace std;

int k_list[5003] = { 0, };
int q_list[5003] = { 0, };
int dp[5003] = { 0, };
int res[5003] = { 0, };
set<int> item;
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, q, m;
	cin >> n >> k >> q >> m;

	for (int i = 0; i < k; i++) {
		cin >> k_list[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> q_list[i];
	}

	for (int i = 0; i < q; i++) {
		item.insert(q_list[i]);
	}
	for (int i = 0; i < k; i++) {
		item.erase(k_list[i]);
	}

	for (auto iter = item.begin(); iter != item.end(); iter++) {
		int key = *iter;
		if (dp[key] == 1) {
			continue;
		}
		for (int j = 1; j <= (5002)/key; j++) {
			dp[j * key] = 1;
		}
	}
	for (int i = 0; i < k; i++) {
		int key = k_list[i];
		dp[key] = 0;
	}

	for (int i = 3; i <= (5002); i++) {
		if (dp[i] == 0) {
			res[i] = res[i-1] + 1;
		}
		else {
			res[i] = res[i - 1];
		}
	}

	int s, e;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << res[e] - res[s - 1] << "\n"; 
	}

	return 0;
}