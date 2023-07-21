#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n, s, t;
vector<pair<ll, ll>> arr;
vector<pair<ll, ll>> res;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		pair<ll, ll> temp;
		cin >> temp.first >> temp.second;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	res.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		pair<int, int> last = res[res.size() - 1];
		if (last.second > arr[i].first) {
			if (last.second >= arr[i].second) {
				res[res.size() - 1].first = arr[i].first;
				res[res.size() - 1].second = arr[i].second;
			}
		}
		else {
			res.push_back(arr[i]);
		}
	}
	cout << res.size() << "\n";
	return 0;
}