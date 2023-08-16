#include <iostream>
#include <queue>
#include <vector>

using namespace std;
pair<int, int> arr[46];
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	arr[0].first = 1;
	arr[0].second = 0;
	arr[1].first = 0;
	arr[1].second = 1;
	arr[2].first = 1;
	arr[2].second = 1;
	for (int i = 3; i <= 45; i++) {
		arr[i].first = arr[i - 1].first + arr[i - 2].first;
		arr[i].second = arr[i - 1].second + arr[i - 2].second;
	}
	cout << arr[n].first << " " << arr[n].second;
	return 0;
}