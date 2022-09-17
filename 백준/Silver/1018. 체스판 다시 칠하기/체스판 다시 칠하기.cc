// 2021-10-24
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<sstream>
//#include<cmath>

using namespace std;

int main()
{
    int w, h;
    cin >> h >> w;

    map<int, string>m; m.clear();
    cin.ignore();
    for (int i = 0; i < h; i++) {
        string a = "";
        getline(cin, a);
        m[i] = a;
    }

    // 솔루션만들기
    string sol_a = "W";
    string sol_b = "B";
    for (int i = 1; i < 9; i++) {
        if (sol_a[i - 1] == 'W') {
            sol_a += "B";
        }
        else {
            sol_a += "W";
        }
        if (sol_b[i - 1] == 'W') {
            sol_b += "B";
        }
        else {
            sol_b += "W";
        }
    }
    /*cout << sol_a << endl;
    cout << sol_b << endl;*/

    int x = w - 7;
    int y = h - 7;
    vector<vector<int>> v; v.clear();
    vector<int> vec; vec.clear();
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            vec.push_back(i);
            vec.push_back(j);
            v.push_back(vec);
            vec.clear();
        }
    }

    map<int, vector<string>> level; level.clear();
    for(int i=0; i<v.size() ; i++) {
        vector<string> str_arr; str_arr.clear();
        for (int j = 0 + v[i][1]; j < 8 + v[i][1]; j++) {
            string str = "";
            for(int k = 0 + v[i][0]; k < 8 + v[i][0]; k++) {
                str += m[j][k];
            }
            str_arr.push_back(str);
        }
        level[i] = str_arr;
    }
    map<int, vector<string>>::iterator iter_v2;
    vector<int> result; result.clear();

    int count = 0;
    for (iter_v2 = level.begin(); iter_v2 != level.end(); iter_v2++) {
        for (int i = 0; i < iter_v2->second.size(); i++) {
            //cout << iter_v2->second[i] << endl;
            for (int q = 0; q < iter_v2->second[i].size(); q++) {
                if (i%2 == 0) {
                    if (sol_a[q] != iter_v2->second[i][q]) {
                        count++;
                    }
                }
                else {
                    if (sol_b[q] != iter_v2->second[i][q]) {
                        count++;
                    }
                }
            }
        }
        //cout << count << endl;
        result.push_back(count);
        count = 0;

        for (int i = 0; i < iter_v2->second.size(); i++) {
            //cout << iter_v2->second[i] << endl;
            for (int q = 0; q < iter_v2->second[i].size(); q++) {
                if (i % 2 == 0) {
                    if (sol_b[q] != iter_v2->second[i][q]) {
                        count++;
                    }
                }
                else {
                    if (sol_a[q] != iter_v2->second[i][q]) {
                        count++;
                    }
                }
            }
        }
        //cout << count << endl;
        result.push_back(count);
        count = 0;
    }
    int min = result[0];
    for (int i = 0; i < result.size(); i++) {
        if (min > result[i]) {
            min = result[i];
        }
    }
    cout << min << endl;
    return 0;
}