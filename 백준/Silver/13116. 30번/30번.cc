#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int parent = a;
		vector<int> arr1;
		vector<int> arr2;
		arr1.push_back(1);
		arr2.push_back(1);
		while (parent !=1){
			arr1.push_back(parent);
			parent /= 2;
		}
		parent = b;
		while (parent !=1){
			arr2.push_back(parent);
			parent /= 2;
		}
		int max_value = 0;
		for (int i = 0; i < arr1.size(); i++) {
			for (int j = 0; j < arr2.size(); j++) {
				if (arr1[i] == arr2[j]) {
					max_value = max(max_value, arr1[i]);
				}
			}
		}
		cout << max_value * 10 << "\n";
	}
	return 0;
}