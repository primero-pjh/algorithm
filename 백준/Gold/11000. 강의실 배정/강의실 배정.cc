#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, s, t;
vector<pair<int, int>> arr;
vector<pair<int, int>> res;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ a, b });
	}
	sort(arr.begin(), arr.end());

	pq.push({ arr[0].second, arr[0].first });
	for (int i = 1; i < n; i++) {
		int top_x = pq.top().first;
		int top_y = pq.top().second;
		if (arr[i].first >= top_x) {
			pq.pop();
			pq.push({ arr[i].second, arr[i].first });
		}
		else {
			pq.push({ arr[i].second, arr[i].first });
		}
		//cout << pq.top().first << ", " << pq.top().second << "\n";

	}
	cout << pq.size() << "\n";
	return 0;
}