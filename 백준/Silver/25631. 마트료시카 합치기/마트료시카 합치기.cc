#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
bool visited[1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int prev = arr[i];
		if (visited[i] == 0) {
			ans++;
			for (int j = i+1; j < n; j++) {
				if (visited[j] == 0) {
					if (prev < arr[j]) {
						prev = arr[j];
						visited[j] = 1;
					}
				}
			}
		}
		else {
			continue;
		}
	}
	cout << ans;
	return 0;
}