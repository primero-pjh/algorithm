//2021-11-13
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

vector<int> arr;
map<string, bool> m;
void dfs(string val, map<int, bool> m2, int k)
{
    if (k == 0) {
        m[val] = true;
        return;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (m2.find(i) != m2.end()) {
            continue;
        }
        m2[i] = true;
        dfs(val + to_string(arr[i]), m2, k-1);
        m2.erase(i);
    }
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    while (true) {
        int a;
        cin >> a;
        arr.push_back(a);
        if (arr.size() == n) {
            break;
        }
    }
    
    for (int i = 0; i < arr.size(); i++) {
        map<int, bool> m;
        m[i] = true;
        dfs(to_string(arr[i]), m, k-1);
    }
    cout << m.size();
}