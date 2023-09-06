#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>

using namespace std;
typedef unsigned long long ull;
int n;
int arr[5001][5001];
bool visited[5001];
ull max_value = 0;
vector<int> v[5001];

void dfs(int top, ull total) {
	max_value = max(max_value, total);
	for (int i = 0; i < v[top].size(); i++) {
		int child = v[top][i];
		if (visited[child] == 0) {
			int value = arr[top][child];
			visited[child] = 1;
			dfs(child, total + value);
			visited[child] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(b);
		v[b].push_back(a);
		arr[a][b] = c;
		arr[b][a] = c;
	}

	visited[1] = 1;
	dfs(1, 0);

	cout << max_value;
	return 0;
}