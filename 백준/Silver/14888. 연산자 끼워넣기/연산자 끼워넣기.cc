// 2021-11-21
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int n;
vector<int> v;
vector<int> res;

int arr[4] = { 0 };
void dfs(int sum, int dep) {
	if (dep == v.size() - 1) {
		res.push_back(sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (arr[i] == 0) {
			continue;
		}
		arr[i]--;
		if (i == 0) {
			dfs(sum + v[dep+1], dep + 1);
		}
		if (i == 1) {
			dfs(sum - v[dep + 1], dep + 1);
		}
		if (i == 2) {
			dfs(sum * v[dep + 1], dep + 1);
		}
		if (i == 3) {
			dfs(sum / v[dep + 1], dep + 1);
		}
		arr[i]++;
	}
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < 4; i++) {
		int a = 0;
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		int sum = 0;
		if (arr[i] == 0) {
			continue;
		}
		if (i == 0) {
			sum = v[0] + v[1];
		}
		if (i == 1) {
			sum = v[0] - v[1];
		}
		if (i == 2) {
			sum = v[0] * v[1];
		}
		if (i == 3) {
			sum = (int)v[0] / v[1];
		}
		arr[i]--;
		dfs(sum, 1);
		arr[i]++;
	}

	int max = res[0];
	int min = res[0];
	for (int i = 0; i < res.size(); i++) {
		if (max < res[i]) {
			max = res[i];
		}
		if (min > res[i]) {
			min = res[i];
		}
	}


	printf("%d\n", max);
	printf("%d\n", min);

	return 0;
}