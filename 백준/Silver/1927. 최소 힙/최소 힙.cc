#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<vector>
using namespace std;

vector<int>v;

int pop_value(int num) {
	if (v.size() == 0) {
		return 0;
	}
	else if (v.size() == 1) {
		int res = v[0];
		v.pop_back();
		return res;
	}
	else {
		int tmp = v[0];
		int res = v[0];
		v[0] = v[v.size() - 1];
		v.pop_back();
		int i = 0;
		int idx = 0;
		
		while (i < v.size() - 1) {
			int left = (i<<1) + 1;
			int right = (i<<1) + 2;

			if (left > v.size() - 1) {
				break;
			}
			if (right > v.size() - 1) {
				idx = left;
				if (v[i] > v[idx]) {
					tmp = v[idx];
					v[idx] = v[i];
					v[i] = tmp;
					i = idx;
				}
				break;
			}

			idx = (v[left] > v[right]) ? right : left;
			if (v[i] > v[idx]) {
				tmp = v[idx];
				v[idx] = v[i];
				v[i] = tmp;
				i = idx;
			}
			else {
				break;
			}
		}
		return res;
	}
}
void insert_value(int num) {
	if (v.size() == 0) {
		v.push_back(num);
		return;
	}
	//  부모노드찾기
	v.push_back(num);
	int idx = v.size() - 1;
	int i = (idx-1) / 2;
	
	while (i>=0) {
		if (v[i] > num) {
			int tmp = v[i];
			v[i] = num;
			v[idx] = tmp;
			idx = i;
			i = (i - 1) / 2;
		}
		else {
			break;
		}
	}
	/*for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	printf("\n");*/
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 0) {
			printf("%d\n", pop_value(a));
		}
		else {
			insert_value(a);
		}
	}
	return 0;
}