#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int arr[11][11];
vector<int> v;
bool visited[11];
int max_value = 0;
void dfs() {
	if (v.size() == 11) {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += arr[i][v[i]];
		}
		max_value = max(max_value, sum);
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (arr[v.size()][i] > 0) {
			if (visited[i] == 0) {
				visited[i] = 1;
				v.push_back(i);
				dfs();
				visited[i] = 0;
				v.pop_back();
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < 11; i++) { visited[i] = 0; }
		v.clear();

		for (int i = 0; i < 11; i++) {
			if (arr[0][i] > 0) {
				visited[i] = 1;
				v.push_back(i);
				dfs();
				visited[i] = 0;
				v.pop_back();
			}
		}
		cout << max_value << "\n";
		max_value = 0;
	}
	return 0;
}