// 2021-10-23
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cmath>
//#include<sstream>
using namespace std;

int main()
{
    int run;
    cin >> run;

    vector<int> v; v.clear();
    vector<int> result; result.clear();

    while (run--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        map<int, bool> check; check.clear();
        map<int, vector<int>> m; m.clear();

        int c_count = 0;
        cin >> c_count;
        for (int i = 0; i < c_count; i++) {
            int x3, y3, r;
            cin >> x3 >> y3 >> r;
            v.push_back(x3);
            v.push_back(y3);
            v.push_back(r);
            m[i] = v;
            v.clear();
        }
        map<int, vector<int>>::iterator iter;
        int value = 0;
        for (iter = m.begin(); iter != m.end(); iter++) {
            // 출발점
            int a = pow(x1 - (iter->second[0]), 2) + pow(y1 - (iter->second[1]), 2);
            int rr = pow(iter->second[2], 2);
            if (a < rr) {
                value++;
                check[iter->first] = true;
            }
            // 도착점
            a = pow(x2 - (iter->second[0]), 2) + pow(y2 - (iter->second[1]), 2);
            rr = pow(iter->second[2], 2);
            if (a < rr) {
                if (check[iter->first] == true) {
                    value--;
                }
                else {
                    value++;
                }
            }
        }
        result.push_back(value);
        value = 0;
    }

    for (int i = 0; i < int(result.size()); i++) {
        cout << result[i] << endl;
    }

    
    return 0;
}