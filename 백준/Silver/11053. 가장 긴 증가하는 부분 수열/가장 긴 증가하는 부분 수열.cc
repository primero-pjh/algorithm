//2021-11-27
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

vector<int> dp;
void lower_bound(int target) {
	int left = 0;
	int right = dp.size();
	while (left != right) {
		if (dp[left] < target) {
			left++;
		}
		else {
			break;
		}
	}
	dp[left] = target;
}

int main() {
	int n;
	cin >> n;
	int arr[1001] = { 0 };
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}

	dp.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (dp[dp.size() - 1] < arr[i]) {
			dp.push_back(arr[i]);
		}
		else {
			lower_bound(arr[i]);
		}
	}

	//for (int i = 0; i < dp.size(); i++) {
	//	printf("%d ", dp[i]);
	//}

	cout << dp.size() << endl;
}