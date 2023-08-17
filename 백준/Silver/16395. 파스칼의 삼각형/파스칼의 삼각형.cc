#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int n, m, k;
int arr[31][31];
bool visited[100001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= 30; i++) {
		arr[i][1] = 1;
		arr[1][i] = 1;
	}
	for (int i = 2; i <= 30; i++) {
		int idx = 2;
		for (int j = 30 - i; j >= 1; j--) {
			arr[i][idx] = arr[i - 1][idx] + arr[i][idx - 1];
			idx++;
		}
	}
	/*for (int i = 1; i <= 11; i++) {
		int idx = 1;
		for (int j = 11 - i; j >= 0; j--) {
			cout << arr[i][idx] << " ";
			idx++;
		}
		cout << "\n";
	}*/
	cout << arr[n - k + 1][k];

	return 0;
}
