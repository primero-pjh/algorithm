#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<sstream>
using namespace std;

int main()
{
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    map<int, int> m;
    m.clear();
    int x = 1;
    int y = 1;
    int z = 1;
    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            for (int k = 0; k < s3; k++) {
                int sum = x + y + z;
                if (m.find(sum) == m.end()) {
                    m[sum] = 0;
                }
                if (m.find(sum) != m.end()) {
                    m[sum] += 1;
                }
                z += 1;
            }
            z = 1;
            y += 1;
        }
        y = 1;
        x += 1;
    }

    map<int, int>::iterator iter;
    int max = m.begin()->second;
    int min = m.begin()->second;
    int max_key = m.begin()->first;
    int min_key = m.begin()->first;
    for (iter = m.begin(); iter != m.end(); iter++) {
        if (max <= iter->second) {
            max = iter->second;
            max_key = iter->first;
        }
    }

    min = max;
    min_key = max_key;
    int count = 0;
    for (iter = m.begin(); iter != m.end(); iter++) {
        if (max == iter->second) {
            count++;
            if (min_key > iter->first) {
                min_key = iter->first;
            }
        }

    }
    if (count > 1) {
        cout << min_key << endl;
        return 0;
    }
    if (count == 1) {
        cout << max_key << endl;
        return 0;
    }
    

}
