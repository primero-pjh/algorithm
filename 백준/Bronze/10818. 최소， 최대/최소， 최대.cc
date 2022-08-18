#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;
vector<int> vec;

int main() {
	int cnt = 0;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		int val = 0;
		scanf("%d", &val);
		vec.push_back(val);
	}
	int min = vec[0];
	int max = vec[0];
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] < min) {
			min = vec[i];
		}
		if (vec[i] > max) {
			max = vec[i];
		}
	}
	printf("%d %d", min, max);
	return 0;
}