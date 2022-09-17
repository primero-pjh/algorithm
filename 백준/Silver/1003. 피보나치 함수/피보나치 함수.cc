// 2021-10-22
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<sstream>
using namespace std;

int main()
{
    int run;
    cin >> run;

    map<int, vector<int>> m;
    m.clear();

    vector<int> v;
    v.clear();
    v.push_back(1);
    v.push_back(0);
    m[0] = v;

    v.clear();
    v.push_back(0);
    v.push_back(1);
    m[1] = v;

    v.clear();
    v.push_back(1);
    v.push_back(1);
    m[2] = v;

    vector<int> result;
    result.clear();
    for (int i = 3; i <= 40; i++) {
        v.clear();
        v.push_back(m[i - 1][1]);
        v.push_back(m[i - 1][0] + m[i - 1][1]);
        m[i] = v;
    }

    while (run--) {
        int a;
        cin >> a;
        result.push_back(a);
        
    }
    for (int i = 0; i < result.size(); i++) {
        int a = result[i];
        cout << m[a][0] << " " << m[a][1] << endl;
    }
    
    return 0;
}