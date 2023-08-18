#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	bool graph[101][101];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][k] && graph[k][j]) {
					graph[i][j] = 1;
				}
			}
		}
	}
	

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			cout << graph[x][y] << " ";
		}
		cout << "\n";
	}
	return 0;
}