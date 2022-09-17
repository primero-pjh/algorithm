 //2021-11-08
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int t = 0; 
	int k, n;
	vector<int> v; v.clear();
	int arr[15][15] = { 0 };
	for (int i = 0; i < 15; i++) {
		arr[0][i] = i+1;
	}
	for (int i = 0; i < 15; i++) {
		arr[i][0] = 1;
	}
	for (int i = 1; i < 15; i++) {
		int j = 1;
		while (j < 15) {
			int sum = 0;
			for (int k = 0; k < j+1; k++) {
				sum += arr[i-1][k];
			}
			arr[i][j] = sum;
			j++;
		}
	}

	/*for (int i = 0; i < 15; i++) {
		cout << arr[14][i] << " ";
	}
	cout << endl;*/
	cin >> t;
	while (t--) {
		cin >> k >> n;
		v.push_back(arr[k][n - 1]);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	
	return 0;
}