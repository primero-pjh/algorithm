#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
using namespace std;

void dfs() {

}
int main() {
	int x;
	vector<int> v;
	int arr[7] = { 64, 32, 16, 8, 4, 2, 1 };
	scanf("%d", &x);
	int sum = 0;
	int idx = 0;
	for (int i = 0; i < 7; i++) {
		if (arr[i] <= x) {
			v.push_back(arr[i]);
			idx = i;
			break;
		}
	}
	sum = v[0];
	for (int i = idx; i < 7; i++) {
		if (sum + arr[i] <= x) {
			v.push_back(arr[i]);
			sum += arr[i];
		}
	}
	printf("%d\n", v.size());
	return 0;
}