#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n, m;
int ans = 0;
vector<int> v;
bool visited[10] = { 0, };

void dfs() {
	if (v.size() == n) {
		int cnt = 0;
		bool temp[10];
		copy(std::begin(visited), std::end(visited), std::begin(temp));
		for (int i = 0; i < v.size(); i++) {
			temp[v[i]] = 0;
		}
		for (int i = 0; i < 10; i++) {
			if (temp[i] == 1) {
				return;
			}
		}
		//cout << "\n";
		ans++;
		return;
	}
	for (int i = 0; i <= 9; i++) {
		v.push_back(i);
		dfs();
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		visited[a] = 1;
	}

	for (int i = 0; i <= 9; i++) {
		v.push_back(i);
		dfs();
		v.pop_back();
	}

	cout << ans << "\n";
	return 0;
}