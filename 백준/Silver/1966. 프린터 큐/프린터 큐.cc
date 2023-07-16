#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[101];
int main() {
	int t;
	cin >> t;
	while (t--) {
		queue<pair<int, int>> q;
		pair<int, int> search;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			arr[i] = a;
			if (i == m) {
				search.first = a;
				search.second = i;
			}
			q.push(pair<int, int> (a, i));
		}
		int idx = 0;
		int cnt = 0;
		sort(arr, arr + n, greater<>());
		/*for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";*/
		//cout << search.first << ", " << search.second << "\n";
		while (!q.empty()) {
			pair<int, int> front = q.front();
			if (arr[idx] == front.first) {
				q.pop();
				cnt++;
				idx++;
				if (search.first == front.first && search.second == front.second) {
					break;
				}
			}
			else {
				q.pop();
				q.push(front);
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}