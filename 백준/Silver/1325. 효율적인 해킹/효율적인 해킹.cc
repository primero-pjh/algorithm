#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;
int visited[10001] = { 0, };

int n, m;
int arr[100001][2] = { 0, };
queue<int> q;
vector<int> inp[10001];
int res[10001] = { 0, };
int dp[10001] = { 0, };
int cnt = 0;
void bfs(int parent) {
	q.push(parent);
	visited[parent] = 1;
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		for (int i = 0; i < inp[top].size(); i++) {
			int child = inp[top][i];
			if (visited[child] == 0) {
				res[parent]++;
				visited[child] = 1;
				q.push(child);
			}
		}
	}
}
void reset() {
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		inp[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		reset();
		int x = inp[i][0];
		bfs(i);
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (res[i] > 0) {
			max = max > res[i] ? max : res[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		if (res[i] == max) {
			cout << i << " ";
		}
	}
	return 0;
}