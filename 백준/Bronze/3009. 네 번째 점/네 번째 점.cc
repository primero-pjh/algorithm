// 2021-11-09
#include<iostream>
#include<math.h>
#include<vector>
#include<map>
using namespace std;


int main()
{
    int x, y;
    vector<vector<int>> v; v.clear();
    map<int, int> a; a.clear();
    map<int, int> b; b.clear();
    map<int, int>::iterator iter;
    for (int i = 0; i < 3; i++) {
        cin >> x >> y;
        vector<int> v2; v2.clear();
        v2.push_back(x);
        v2.push_back(y);
        v.push_back(v2);
    }
    
    for (int i = 0; i < 3; i++) {
        if (a.find(v[i][0]) == a.end()) {
            a[v[i][0]] = 0;
        }
        if (a.find(v[i][0]) != a.end()) {
            a[v[i][0]] += 1;
        }

        if (b.find(v[i][1]) == b.end()) {
            b[v[i][1]] = 0;
        }
        if (b.find(v[i][1]) != b.end()) {
            b[v[i][1]] += 1;
        }
    }
    for (iter = a.begin(); iter != a.end(); iter++) {
        if (iter->second == 1) {
            cout << iter->first << " ";
        }
    }
    for (iter = b.begin(); iter != b.end(); iter++) {
        if (iter->second == 1) {
            cout << iter->first << endl;
        }
    }
    return 0;
}