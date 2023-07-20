#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
char arr[2001][2001];
int n, m, k;

int dp_b[2001][2001];
int dp_w[2001][2001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i+1][j+1] = str[j];
		}
	}
	// B
	char start_alpha = 'B';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int idx = 0;
			if (arr[i][j] != start_alpha) {
				idx = 1;
			}
			dp_b[i][j] = dp_b[i - 1][j] + dp_b[i][j - 1] - dp_b[i - 1][j - 1] + idx;
			start_alpha = start_alpha == 'B' ? 'W' : 'B';
		}
		start_alpha = i % 2 == 0 ? 'B' : 'W';
	}
	start_alpha = 'W';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int idx = 0;
			if (arr[i][j] != start_alpha) {
				idx = 1;
			}
			dp_w[i][j] = dp_w[i - 1][j] + dp_w[i][j - 1] - dp_w[i - 1][j - 1] + idx;
			start_alpha = start_alpha == 'B' ? 'W' : 'B';
		}
		start_alpha = i % 2 == 1 ? 'B' : 'W';
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dp_b[i][j] << " ";
		}
		cout << "\n";
	}
	cout << " ---- " << "\n";

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dp_w[i][j] << " ";
		}
		cout << "\n";
	}*/

	int min_value = 2000 * 2000;
	for (int i = k; i <= n; i++) {
		for (int j = k; j <= m; j++) {
			min_value = min(min_value, (dp_b[i][j] - (dp_b[i-k][j] + dp_b[i][j-k]) + dp_b[i - k][j - k]));
			min_value = min(min_value, (dp_w[i][j] - (dp_w[i-k][j] + dp_w[i][j-k]) + dp_w[i - k][j - k]));
		}
	}
	cout << min_value << "\n";
	return 0;
}