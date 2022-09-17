// 2021-10-22
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<sstream>
using namespace std;

int main()
{
    int count = 0;
    map<int, vector<int>> m;
    m.clear();
    cin >> count;
    map<int, int> result;
    result.clear();

    for (int i = 0; i < count; i++) {
        int a, b, c, d, e;
        vector<int> v;
        v.clear();
        cin >> a >> b >> c >> d >> e;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
        v.push_back(e);
        m[i + 1] = v;
        v.clear();
    }
    map<int, vector<int>>::iterator iter;

    for (iter = m.begin(); iter != m.end(); iter++) {
        result[iter->first] = 0;
            
        for (int j = 1; j < count + 1; j++) {
            if (iter->first == j) {
                continue;
            }

            if (iter->second[0] == m[j][0] || iter->second[1] == m[j][1] || iter->second[2] == m[j][2] || iter->second[3] == m[j][3] || iter->second[4] == m[j][4]) {
                result[iter->first] += 1;
            }
        }
    }

    map<int, int>::iterator iter2;
    int max_key = result.begin()->first;
    int max = result.begin()->second;
  
   
    for (iter2 = result.begin(); iter2 != result.end(); iter2++) {
        /*cout << "first:" << iter2->first << endl;
        cout << "second:" << iter2->second << endl;*/
        if (max < iter2->second) {
            max = iter2->second;
            max_key = iter2->first;
        }
       
    }
    count = 0;
    int min_key = max_key;
    int min = max;
    for (iter2 = result.begin(); iter2 != result.end(); iter2++) {
        if (max == iter2->second) {
            count++;
            if (min > iter2->second) {
                min = iter2->second;
                min_key = iter2->first;
            }
        }
    }
    if (count > 1) {
        cout << min_key;
        return 0;
    }
    else {
        cout << max_key;
        return 0;
    }
    return 0;
}