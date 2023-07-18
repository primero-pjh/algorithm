#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[31][31];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int max_value = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i+1; j < m; j++) {
			for (int k = i + 2; k < m; k++) {
				vector<int> list;
				for (int q = 0; q < n; q++) {
					list.push_back(max(arr[q][i], max(arr[q][j], arr[q][k])));
				}
				//sort(list.begin(), list.end());
				int sum = 0;
				//int idx = list.size() - 1;
				for (int q = 0; q < list.size(); q++) {
					sum += list[q];
					//idx--;
				}
				max_value = max(max_value, sum);
			}
		}
	}
	cout << max_value << "\n";
	return 0;
}