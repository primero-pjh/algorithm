#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
map<int, vector<int>> m;
bool visited[500001];
int res[500001];
int cnt = 0;
int n;
void dfs(int parent, int num) {
	//res[parent] = num + 1;
	for (int i = 0; i < m[parent].size(); i++) {
		int child = m[parent][i];
		if (visited[child] == 0) {
			cnt++;
			res[child] = num + 1;
			visited[child] = 1;
			dfs(child, num + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int a = v[i].first;
		int b = v[i].second;
		m[a].push_back(b);
		m[b].push_back(a);
	}
	/*for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << ": ";
		for (int i = 0; i < iter->second.size(); i++) {
			cout << iter->second[i] << " ";
		}
		cout << "\n";
	}*/
	vector<int> graph;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->first != 1 && iter->second.size() == 1) {
			graph.push_back(iter->first);
		}
	}

	/*cout << "---\n";
	for (int i = 0; i < graph.size(); i++) {
		cout << graph[i] << " ";
	}
	cout << "\n";*/

	visited[1] = 1;
	dfs(1, 0);

	int ans = 0;
	for (int i = 0; i < graph.size(); i++) {
		ans += res[graph[i]];
	}
	//cout << ans << "\n";
	if (ans % 2 == 0) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
}