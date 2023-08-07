#include <iostream>
#include <queue>

using namespace std;

queue<int> truck;
deque<pair<int, int>> bridge;
int n, w, l;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> w >> l;
	
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		truck.push(a);
	}
	int ans = 0;
	int sum = 0;
	while (!truck.empty()) {
		int front = truck.front();
		sum += front;
		truck.pop();
		bridge.push_back({ front, 0 });
		while (!bridge.empty()) {
			for (int i = 0; i < bridge.size(); i++) {
				bridge[i].second++;
			}
			ans++;

			if (bridge.front().second == w) {
				sum -= bridge.front().first;
				bridge.pop_front();
			}
			
			if (!truck.empty() && sum + truck.front() <= l) {
				bridge.push_back({ truck.front(), 0 });
				sum += truck.front();
				truck.pop();
			}
		}
	}

	cout << ans + 1;
	return 0;
}