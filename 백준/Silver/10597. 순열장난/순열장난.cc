#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str;
vector<int> v;
bool arr[51];
int max_value = 0, len = 0;
void dfs(int idx) {
	if (idx >= len) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		exit(0);
	}
	string temp = "";
	for (int i = idx; i <= idx + 1; i++) {
		temp += str[i];
		int num = stoi(temp);
		if (num > max_value) { continue; }
		//if (num <= 0) { continue; }
		if (arr[num] == 1) { continue; }
		if (arr[num] == 0) {
			arr[num] = 1;
			v.push_back(num);
			dfs(i + 1);
			v.pop_back();
			arr[num] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> str;
	len = str.size();
	if (len < 10) {
		max_value = len;
	}
	else {
		max_value = 9 + (len - 9) / 2;
	}
	dfs(0);
	
	return 0;
}