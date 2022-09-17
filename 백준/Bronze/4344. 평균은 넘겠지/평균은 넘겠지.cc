#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
vector<double> res;

int main() {
	int cnt = 0;
	scanf("%d", &cnt);
	

	for (int i = 0; i < cnt; i++) {
		int val = 0;
		scanf("%d", &val);
		vector<int> vec;
		for (int j = 0; j < val; j++) {
			int a = 0;
			scanf("%d", &a);
			vec.push_back(a);
		}
		
		double avg = 0;
		int sum = 0;
		for (int k = 0; k < val; k++) {
			sum += vec[k];
		}
		avg = (double)sum / val;
		int success = 0;
		for (int q = 0; q < val; q++) {
			if (avg < vec[q]) {
				success++;
			}
		}
		//printf("%f, %d, %d, %d\n", avg, sum, success, val);
		res.push_back(double(success * 100)/val);
	}
	for (int i = 0; i < res.size(); i++) {
		printf("%.3f", res[i]);
		cout << "\%" << endl;
	}
	return 0;
}