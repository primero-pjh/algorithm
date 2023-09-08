#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int arr[1001];
map<int, bool> graph;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		graph[arr[i]] = 0;
	}
	sort(arr, arr + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (graph[arr[i]] == 0) {
			double start = arr[i] - 0.5;
			double end = start + l;
			for (int j = i; j < n; j++) {
				if (arr[j] >= start && arr[j] <= end) {
					graph[arr[j]] = true;
				}
			}
			ans++;
		}
	}
	cout << ans;

	return 0;
}