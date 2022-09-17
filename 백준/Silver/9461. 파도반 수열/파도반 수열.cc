#include<iostream>
#include<vector>

using namespace std;

unsigned long long arr[100];

unsigned long long dfs(int a) {
	if (arr[a] != 0) {
		return arr[a];
	}
	return arr[a] = dfs(a - 1) + dfs(a - 5);
}

int main() {
	int n;
	cin >> n;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	arr[6] = 3;
	arr[7] = 4;
	arr[8] = 5;
	arr[9] = 7;
	arr[10] = 9;
	
	while (n--) {
		int a;
		cin >> a;
		if (a <= 10) {
			cout << arr[a] << endl;
		}
		else {
			cout << dfs(a) << endl;
		}
	}
	return 0;
}
