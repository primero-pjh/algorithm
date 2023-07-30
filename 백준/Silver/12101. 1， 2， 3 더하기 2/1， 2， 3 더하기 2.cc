#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> v;
vector<vector<int>> res;
void dfs(int sum) {
	if (sum == n) {
		res.push_back(v);
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (sum + i > n) {
			continue;
		}
		v.push_back(i);
		dfs(sum + i);
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	for (int i = 1; i <= 3; i++) {
		if (i > n) {
			continue;
		}
		v.push_back(i);
		dfs(i);
		v.pop_back();
	}
	
	if (res.size() < k) {
		cout << -1;
		exit(0);
	}
	for (int i = 0; i < res[k - 1].size(); i++) {
		if (i == res[k - 1].size() - 1) {
			cout << res[k - 1][i];
		}
		else {
			cout << res[k - 1][i] << "+";
		}
	}

	return 0;
}