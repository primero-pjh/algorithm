//2021-12-03
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> dp;
vector<int> res;
int arr[1001] = { 0 };

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
		dp.push_back(arr[i]);
	}
	res.push_back(arr[0]);


	for (int i = 1; i < n; i++) {
		int m = 0;
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			int x = arr[i]; 
			int sum = 0;
			if (dp[j] < arr[i]) {
				sum = res[j] + arr[i];
				m = max(m, sum);
				cnt++;
			}
		}
		if (cnt == 0) {
			res.push_back(arr[i]);
		}
		else {
			res.push_back(m);
		}
	}

	int max = 0;
	for (int i = 0; i < res.size(); i++) {
		//printf("%d ", res[i]);
		if (max < res[i]) {
			max = res[i];
		}		
	}
	cout << max << endl;
}