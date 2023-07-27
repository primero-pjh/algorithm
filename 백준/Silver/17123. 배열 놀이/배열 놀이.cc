#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, t;
vector<pair<int, int>> v;
int arr[1001][1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		int r1, c1, r2, c2, v;
		vector<int> rows;
		vector<int> columns;
		for (int i = 0; i < n; i++) {
			int sum1 = 0, sum2 = 0;
			for (int j = 0; j < n; j++) {
				sum1 += arr[i][j];
				sum2 += arr[j][i];
			}
			rows.push_back(sum1);
			columns.push_back(sum2);
		}

		for (int i = 0; i < m; i++) {
			cin >> r1 >> c1 >> r2 >> c2 >> v;
			for (int j = r1 - 1; j <= r2 - 1; j++) {
				rows[j] += (c2 - c1 + 1) * v;
			}
			for (int j = c1 - 1; j <= c2 - 1; j++) {
				columns[j] += (r2 - r1 + 1) * v;
			}
		}

		for (int i = 0; i < n; i++) {
			cout << rows[i] << " ";
		}
		cout << "\n";
		for (int i = 0; i < n; i++) {
			cout << columns[i] << " ";
		}
		cout << "\n";
	}



	return 0;
}