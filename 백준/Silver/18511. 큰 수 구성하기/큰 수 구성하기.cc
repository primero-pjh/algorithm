#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int arr[3];
int n, k;
int len = 0;
int max_value = 0;
void req(string s) {
	if (s.size() > len) {
		return;
	}
	int num = stoi(s);
	if (num <= n) {
		max_value = max(num, max_value);
	}
	for (int i = 0; i < k; i++) {
		s += arr[i] + '0';
		req(s);
		s.pop_back();
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	len = to_string(n).size();
	for (int i = 0; i < k; i++) {
		string s = "";
		s += (arr[i] + '0');
		req(s);
	}

	/*sort(v.begin(), v.end());
	cout << v[v.size() - 1] << "\n";*/
	cout << max_value << "\n";
	return 0;
}