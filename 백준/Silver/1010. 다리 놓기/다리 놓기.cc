//// 2021-10-23
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cmath>
//#include<sstream>
using namespace std;

unsigned long long fact(unsigned long long start, unsigned long long end) {
    unsigned long long value = 1;
    if (end == 0) {
        while (start != 1) {
            value *= start;
            start--;
        }
        return value;
    }
    else {
        while (start != end) {
            value *= start;
            start--;
        }
        return value;
    }
}

int main()
{
    int run;
    cin >> run;

    map<int, vector<int>> m;
    m.clear();

    for (int i = 0; i < run; i++) {
        int N, M;
        vector<int> v; v.clear();
        cin >> N >> M;
        v.push_back(N);
        v.push_back(M);
        m[i] = v;
        v.clear();
    }

    map<int, vector<int>>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second[0] == 0 || iter->second[1] == 0) {
            cout << 0 << endl;
            continue;
        }
        if (iter->second[0] == iter->second[1]) {
            cout << 1 << endl;
            continue;
        }
        unsigned long long count = 0;
        
        
        if (iter->second[1] - iter->second[0] > iter->second[0]) {
            count = fact(iter->second[1], iter->second[1]-iter->second[0]) / fact(iter->second[0], 0);
        }
        else {
            count = fact(iter->second[1], iter->second[0]) / fact(iter->second[1] - iter->second[0], 0);
        }
        cout << count << endl;
    }

    return 0;
}