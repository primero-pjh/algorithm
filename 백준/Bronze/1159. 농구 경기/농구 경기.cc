// 2021-10-21
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<sstream>
using namespace std;

int main()
{
    int count;
    cin >> count;

    map<char, int> m;
    m.clear();
    
    vector<string> v;
    cin.ignore();
    for (int i = 0; i < count; i++) {
        string a = "";
        getline(cin, a);
        v.push_back(a);
    }

    for (int i = 0; i < count; i++) {
        if (m.find(v[i][0]) == m.end()) {
            m[v[i][0]] = 0;
        }
        if (m.find(v[i][0]) != m.end()) {
            m[v[i][0]]++;
        }
    }

    map<char, int>::iterator iter;
    count = 0;
    for (iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second >= 5) {
            cout << iter->first;
            count++;
        }
    }
    if (count == 0) {
        cout << "PREDAJA";
    }
    return 0;
}