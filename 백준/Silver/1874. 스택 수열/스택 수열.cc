#include <iostream>
#include <vector>

using namespace std;

int arr[100001] = { 0, };
vector<char> result;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> v;
	int idx = 1;
	int i = 0;
	while (i < n) {
		if (idx > n + 1) {
			cout << "NO" << "\n";
			exit(0);
		}
		if (v.empty()) {
			v.push_back(idx);
			result.push_back('+');
			idx++;
		}
		else {
			int back = v.back();
			if (back == arr[i]) {
				v.pop_back();
				result.push_back('-');
				i++;
			}
			else {
				v.push_back(idx);
				result.push_back('+');
				idx++;
			}
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	return 0;
}