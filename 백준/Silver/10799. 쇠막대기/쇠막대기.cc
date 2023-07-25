#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> lazor;
vector<pair<int, int>> line;

stack<int> s;

int main() {
	string str;
	cin >> str;
	string new_str = ""; new_str += str[0];
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == ')') {
			if (str[i - 1] == '(') {
				if (!new_str.empty()) {
					new_str.pop_back();
				}
				new_str += "0";
			}
			else {
				new_str += ")";
			}
		}
		else {
			new_str += "(";
		}
	}
	for (int i = 0; i < new_str.size(); i++) {
		if (new_str[i] == '(') {
			s.push(i);
		}
		else if(new_str[i] == ')') {
			line.push_back({ s.top(), i });
			s.pop();
		}
		else {
			lazor.push_back(i);
		}
	}
	int ans = 0;
	for (int i = 0; i < line.size(); i++) {
		int sum = 0;
		for (int j = 0; j < lazor.size(); j++) {
			if (lazor[j] >= line[i].first && lazor[j] <= line[i].second) {
				sum++;
			}
		}
		ans += (sum + 1);
	}
	cout << ans;
	return 0;
}