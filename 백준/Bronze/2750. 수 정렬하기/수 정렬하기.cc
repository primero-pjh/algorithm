#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

vector<int> vec;

int main() {
	int num = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int a = 0;
		cin >> a;
		vec.push_back(a);
	}

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.size(); j++) {
			int temp = 0;
			if (vec[i] < vec[j]) {
				temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < num; i++) {
		printf("%d\n", vec[i]);
	}
	return 0;
}