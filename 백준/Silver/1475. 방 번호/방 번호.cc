#include <iostream>
#include <string>

using namespace std;

int n, ans = 0;
int arr[10] = { 0, };
bool visited[10] = { 0, };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		arr[str[i] - '0']++;
	}

	while (1) {
		int cnt = 0;
		for (int i = 0; i < 10; i++) {
			if (arr[i] <= 0) {
				cnt++;
			}
		}
		if (cnt == 10) {
			break;
		}
		for (int i = 0; i < 10; i++) {
			visited[i] = 0;
		}
		for (int i = 0; i < 10; i++) {
			if (arr[i] > 0) {
				if (i == 6) {
					if (visited[6] == 0) {
						arr[i]--;
						visited[6] = 1;
					}
					if (arr[i] > 0 && visited[9] == 0) {
						arr[i]--;
						visited[9] = 1;
					}
				} else if (i == 9) {
					if (visited[9] == 0) {
						arr[i]--;
						visited[9] = 1;
					}

					if (arr[i] > 0 && visited[6] == 0) {
						arr[i]--;
						visited[6] = 1;
					}
				}
				else {
					if (visited[i] == 0) {
						arr[i]--;
						visited[i] = 1;
					}
				}
			}
		}
		ans++;
	}
	cout << ans;
	return 0;
}