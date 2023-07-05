#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, long long[100001]> m;
int arr[100001] = { 0, };
int arr2[100001] = { 0, };

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	long long sum = 0;
	for (int i = 1; i < n; i++) {
		sum += arr[i];
	}


	long long res = 0;
	for (int i = 0; i < n - 1; i++) {
		res += (sum * arr[i]);
		sum -= arr[i+1];
	}
	cout << res << "\n";
	
	return 0;
}