#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int search(vector<int> v) {
	sort(v.begin(), v.end());
	return v[2];
}
void recursion(vector<int> v) {
	int v_size = v.size();
	int len = sqrt(v_size);
	if (v_size == 4) {
		cout << search(v) << "\n";
		exit(0);
	}
	int cnt = len / 2;
	int a, b, c, d;
	a = 0;
	b = 1;
	c = a + len;
	d = b + len;
	vector<int> arr;
	for (int i = 0; i < cnt; i++) {
		
		for (int j = 0; j < cnt; j++) {
			vector<int> temp;
			temp.push_back(v[a]);
			temp.push_back(v[b]);
			temp.push_back(v[c]);
			temp.push_back(v[d]);
			//cout << v[a] << ", " << v[b] << ", " << v[c] << ", " << v[d] << "\n";
			int second = search(temp);
			//cout << second << "\n";
			arr.push_back(second);
			a += 2;
			b += 2;
			c += 2;
			d += 2;
		}
		a += len;
		b += len;
		c += len;
		d += len;
	}

	recursion(arr);
}

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			arr.push_back(a);
		}
	}

	recursion(arr);
	return 0;
}