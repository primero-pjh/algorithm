#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int arr[3001];
bool visited[3001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			visited[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		if (n == 1) {
			cout << "Jolly\n";
			continue;
		}
		for (int i = 1; i < n; i++) {
			int value = abs(arr[i] - arr[i - 1]);
			visited[value] = 1;
		}
		int cnt = 0;
		for (int i = 1; i <= n - 1; i++) {
			if (visited[i] == 1) {
				cnt++;
			}
		}
		if (cnt == n - 1) {
			cout << "Jolly\n";
		}
		else {
			cout << "Not jolly\n";
		}
		
	}
	return 0;
}