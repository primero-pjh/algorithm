#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
ll n, m;
ll arr[1001];
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}

	while (m--) {
		ll first = pq.top();
		pq.pop();
		ll second = pq.top();
		pq.pop();
		ll result = first + second;
		pq.push(result);
		pq.push(result);
	}

	ll sum = 0;
	while (!pq.empty()) {
		ll top = pq.top();
		pq.pop();
		sum += top;
	}
	cout << sum << "\n";

	return 0;
 }