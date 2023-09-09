#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1001];
int dp[1001];
int visited[1001];
vector<int> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] == 0) {
					dp[i] = dp[j] + 1;
					visited[i] = j;
				}
				else {
					if (dp[i] < dp[j] + 1) {
						dp[i] = dp[j] + 1;
						visited[i] = j;
					}
				}
			}
		}
	}
	/*for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		cout << visited[i] << " ";
	}
	cout << "\n";*/

	int max_value = 0;
	for (int i = 1; i <= n; i++) {
		max_value = max(max_value, dp[i]);
	}
	int idx = 0;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (dp[i] == max_value) {
			idx = i;
		}
	}
	for (int i = 0; i < max_value; i++) {
		v.push_back(arr[idx]);
		idx = visited[idx];
	}

	cout << max_value << "\n";
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
	return 0;
}