#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[101];
int type[4];

int min_value = 1000000000;
int max_value = -1000000000;
void dfs(int sum, int idx) {
	if (idx == n - 1) {
		max_value = max(max_value, sum);
		min_value = min(min_value, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int temp = 0;
		if (type[i] <= 0) {
			continue;
		}
		if (i == 0) {
			temp = (sum + arr[idx + 1]);
		}
		else if (i == 1) {
			temp = (sum - arr[idx + 1]);
		}
		else if (i == 2) {
			temp = (sum * arr[idx + 1]);
		}
		else if (i == 3) {
			temp = (sum / arr[idx + 1]);
		}
		type[i]--;
		dfs(temp, idx + 1);
		type[i]++;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> type[i];
	}

	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (type[i] == 0) { continue; }
		if (i == 0) {
			sum = arr[0] + arr[1];
		}
		else if (i == 1) {
			sum = arr[0] - arr[1];
		}
		else if (i == 2) {
			sum = arr[0] * arr[1];
		}
		else if (i == 3) {
			sum = arr[0] / arr[1];
		}
		type[i]--;
		dfs(sum, 1);
		type[i]++;
	}

	cout << max_value << "\n";
	cout << min_value << "\n";

	return 0;
}