// 2021-10-26
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<algorithm>
//#include<cmath>
//#include<sstream>
using namespace std;

int main()
{
    int w, h;
    cin >> h >> w;

    cin.ignore();

    
    vector<string> v; v.clear();
    map<string, int> m; m.clear();
    for (int i = 0; i < h; i++) {
        string a = "";
        getline(cin, a);
        v.push_back(a);
        m[a] = 0;
    }

    int k;
    cin >> k;
    vector<int> result; result.clear();
    if (k % 2 == 1) {
        for (int i = 0; i < v.size(); i++) {
            int count = 0;
            for (int j = 0; j < v[i].size(); j++) {
                if (v[i][j] == '0') {
                    count++;
                }
            }
            if (count % 2 == 1 && count <= k) {
                m[v[i]]++;
            }
        }
    }
    else {
        for (int i = 0; i < v.size(); i++) {
            int count = 0;
            for (int j = 0; j < v[i].size(); j++) {
                if (v[i][j] == '0') {
                    count++;
                }
            }
            if (count % 2 == 0 && count <= k) {
                m[v[i]]++;
            }

        }
    }
    
    map<string, int>::iterator iter;
    
    int max = 0;
    for (iter = m.begin(); iter != m.end(); iter++) {
        if (max < iter->second) {
            max = iter->second;
        }
        /*cout << "first: " << iter->first << endl;
        cout << "second: " << iter->second << endl;*/
    }
    cout << max << endl;

    return 0;
}