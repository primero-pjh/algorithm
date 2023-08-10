#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, res;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p1;
priority_queue<int, vector<int>, greater<int>> p2;
vector<pair<int, int>> v;
int arr[100001] = { 0, };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p, q;
		cin >> p >> q;
		v.push_back({ p, q });
	}
	sort(v.begin(), v.end());
	p1.push({ v[0].second, 0 });
	arr[0]++;
	res = 1;
	for (int i = 1; i < n; i++) {
		int top = p1.top().first;
		int idx = p1.top().second;
		if (top > v[i].first) {
			if (!p2.empty()) {
				p1.push({ v[i].second, p2.top() });
				arr[p2.top()]++;
				p2.pop();
			}
			else {
				p1.push({ v[i].second, res });
				arr[res++]++;
			}
		}
		else {
			while (!p1.empty()) {
				if (p1.top().first <= v[i].first) {
					p2.push(p1.top().second);
					p1.pop();
				}
				else {
					break;
				}
			}
			p1.push({ v[i].second, p2.top() });
			arr[p2.top()]++;
			p2.pop();
		}
	}

	cout << res << "\n";
	for (int i = 0; i < res; i++) {
		cout << arr[i] << " ";
	}
	return 0;

}