#include <iostream>
#include <vector>

using namespace std;

int n, k;
int arr[10];
bool visited[10];
vector<int> v;

int ans = 0;
void dfs(int idx, int weight) {
	int value = arr[idx];
	if (v.size() == n) {
		if (weight + value - k >= 500) {
			ans++;
		}
		return;
	}
	if (weight + value - k < 500) {
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			v.push_back(i);
			visited[i] = 1;
			dfs(i, weight + value - k);
			v.pop_back();
			visited[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		visited[i] = 1;
		dfs(i, 500);
		v.pop_back();
		visited[i] = 0;
	}
	cout << ans << "\n";
}