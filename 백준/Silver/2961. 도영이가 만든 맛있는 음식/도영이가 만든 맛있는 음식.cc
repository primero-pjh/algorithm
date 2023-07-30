#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;
int n;
vector<pair<int, int>> v;
bool visited[11];

ll min_value = 999999999;
void dfs(vector<int> temp) {
	ll sum1 = 1;
	ll sum2 = 0;
	for (int i = 0; i < temp.size(); i++) {
		if (sum1 * v[temp[i]].first - sum2 >= 999999999) {
			return;
		}
		sum1 *= v[temp[i]].first;
		sum2 += v[temp[i]].second;
	}
	//cout << sum1 - sum2 << "\n";
	if (min_value > abs(sum1 - sum2)) {
		min_value = abs(sum1 - sum2);
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			temp.push_back(i);
			visited[i] = 1;
			dfs(temp);
			visited[i] = 0;
			temp.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	vector<int> temp;
	for (int i = 0; i < n; i++) {
		temp.push_back(i);
		visited[i] = 1;
		dfs(temp);
		visited[i] = 0;
		temp.pop_back();
	}

	cout << min_value;
	return 0;
}