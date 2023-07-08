#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int arr[51] = { 0, };
map<int, set<int>> graph;

int n, idx;
bool visited[51];
void dfs(int parent) {
	for (auto child = graph[parent].begin(); child != graph[parent].end(); child++) {
		dfs(*child);
		
	}
	graph.erase(parent);
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		graph[i];
	}

	for (int i = 0; i < n; i++) {
		int child = i;
		int parent = arr[i];
		if (parent != -1) {
			graph[parent].insert(child);
		}
	}

	cin >> idx;
	dfs(idx);

	int sum = 0;
	for (auto iter = graph.begin(); iter != graph.end(); iter++) {
		iter->second.erase(idx);
	}
	for (auto iter = graph.begin(); iter != graph.end(); iter++) {
		if (iter->second.size() == 0) {
			sum++;
		}
	}
	cout << sum << "\n";
	return 0;
}