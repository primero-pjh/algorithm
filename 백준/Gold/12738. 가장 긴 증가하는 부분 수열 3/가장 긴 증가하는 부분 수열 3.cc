#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[1000001];
vector<int> v;

void b_search(int idx) {
	int start = 0;
	int end = v.size() - 1;
	while (1) {
		int mid = (start + end) / 2;
		if (start == end) {
			v[mid] = arr[idx];
			return;
		}
		if (arr[idx] > v[mid]) {
			start = mid + 1;
		} else if (arr[idx] == v[mid]) {
			return;
		} else if (arr[idx] < v[mid]) {
			end = mid;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	v.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (arr[i] > v.back()) {
			v.push_back(arr[i]);
		}
		else if (arr[i] == arr[i - 1]) {
			continue;
		}
		else {
			b_search(i);
		}
	}

	cout << v.size();

	return 0;
}