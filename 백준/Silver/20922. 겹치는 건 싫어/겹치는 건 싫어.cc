#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int arr[200001] = { 0, };
map<int, vector<int>> graph;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int idx = -1;
	int max_value = 0;
	for (int i = 0; i < n; i++) {
		int item = arr[i];
		graph[item].push_back(i);
		if (graph[item].size() > k) {
			idx = max(idx, graph[item][0]);
			//cout << "idx:" << idx << "\n";
			graph[item].erase(graph[item].begin() + 0);
		}
		max_value = max(max_value, i-idx);
	}

	cout << max_value;
	return 0;
}