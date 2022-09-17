#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<cmath>

using namespace std;

int main()
{
    int run;
    cin >> run;

    int x1, y1, r1, x2, y2, r2;
    map<int, vector<int>>m;
    m.clear();
    for (int i = 0; i < run; i++) {
        vector<int> v;
        v.clear();
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        v.push_back(x1);
        v.push_back(y1);
        v.push_back(r1);
        v.push_back(x2);
        v.push_back(y2);
        v.push_back(r2);
        m[i] = v;
        v.clear();
    }

    map<int, vector<int>>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++) {
        x1 = iter->second[0]; y1 = iter->second[1]; r1 = iter->second[2];
        x2 = iter->second[3]; y2 = iter->second[4]; r2 = iter->second[5];

        double d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
        if (d == 0 && r1 == r2) {     // 안만남
            cout << -1 << endl;
            continue;
        }

        else if (d < abs(r1 - r2)) {     // 안만남
            cout << 0 << endl;
            continue;
        }

        else if (d > r1 + r2) {     // 안만남
            cout << 0 << endl;
            continue;
        }

        else if (d == r1 + r2) {     // 한점에 만남
            cout << 1 << endl;
            continue;
        }
        else if (d == abs(r1 - r2)) {     // 한점에 만남
            cout << 1 << endl;
            continue;
        }
        else if (d < r1 + r2) {  // 두점에서만남
            cout << 2 << endl;
            continue;
        }

    }
    return 0;
}