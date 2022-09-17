// 2021-10-27
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v; v.clear();
	vector<int> result; result.clear();
	cin.ignore();
	for (int i = 0; i < N; i++) {
		vector<int> x; x.clear();
		string a = "";
		getline(cin, a);
		for (int j = 0; j < M; j++) {
			x.push_back(a[j] - '0');
		}
		v.push_back(x);
	}
	int x = N;
	int y = M;
	int c = 0;
	if (x == 1 || y == 1) {
		cout << 1 << endl;
		return 0;
	}
	while (true) {
		if (x == 0 || y == 0) {
			break;
		}
		//cout << x << y << endl;
		int a = 0; int b = 0; 
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				//cout << b << ',' << a << ' ';
				//cout << v[b][a] << ' ' << v[b][a + c] << ' ' << v[b + c][a] << ' ' << v[b + c][a + c] << endl;
				if (v[b][a] == v[b][a + c] && v[b][a + c] == v[b + c][a] && v[b + c][a] == v[b + c][a + c] && v[b+c][a+c] == v[b][a]) {
					result.push_back(pow((c+1), 2));
				}
				a++;
			}
			a = 0;
			b++;
		}
		//cout << endl;
		b = 0;
		c++;

		x--;
		y--;
	}
	int max = result[0];
	for (int i = 0; i < result.size(); i++) {
		//cout << result[i] << endl;
		if (max < result[i]) {
			max = result[i];
		}
	}
	cout << max << endl;

	return 0;
}