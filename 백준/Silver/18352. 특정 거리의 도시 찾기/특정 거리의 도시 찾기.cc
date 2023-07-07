#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

map<int, vector<int>> item;
vector<int> v;
queue<int> q;
//int res[300001] = { 0, };
bool visited[300001];
map<int, int> graph;

int n, m, k, x;

int idx = 0;
void bfs(int top) {
	q.push(top);
	graph[top] = idx;
	idx++;
	visited[top] = 1;
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		for (int i = 0; i < item[parent].size(); i++) {
			int child = item[parent][i];
			if (visited[child] == 0) {
				graph[child] = graph[parent] + 1;
				q.push(child);
				visited[child] = 1;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		item[a].push_back(b);
	}

	bfs(x);

	for (auto iter = graph.begin(); iter != graph.end(); iter++) {
		//cout << iter->first << ": " << iter->second << "\n";
		if (iter->second == k) {
			v.push_back(iter->first);
		}
	}

	sort(v.begin(), v.end());
	if (v.size() == 0) {
		cout << -1 << "\n";
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << "\n";
		}
	}
	return 0;
}