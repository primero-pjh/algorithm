// 2021-10-23
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
//#include<cmath>
//#include<sstream>
using namespace std;

vector<string> split2(string s, string divid) {
    vector<string> v;
    int start = 0;
    int d = s.find(divid);
    while (d != -1) {
        v.push_back(s.substr(start, d - start));
        start = d + 1;
        d = s.find(divid, start);
    }
    v.push_back(s.substr(start, d - start));

    return v;
}

void left(vector<string> v, int count) {
    while (count--) {

    }
}

int main()
{
    int run, size;
    cin >> size >> run;

    vector<int> v; v.clear();
    cin.ignore();
    string a = "";
    getline(cin, a);
    vector<string> v2; v2.clear();
    v2 = split2(a, " ");
    for (int i = 0; i < v2.size(); i++) {
        v.push_back(stoi(v2[i]));
    }
    
    map<int, bool> m; m.clear();
    int count = 0;
    string type = "";
    while (run--) {
        v[0] - 1 > (size - v[0] + 1) ? type = "right" : type = "left";
        if (type == "left") {
            int len = v[0] - 1;
            for (int j = 0; j < len; j++) {
                for (int k = 0; k < v.size(); k++) {
                    v[k]--;
                    if (v[k] < 1) {
                        v[k] = size;
                    }
                }
                count++;
            }
        }
        else {
            int  len = size - v[0] + 1;
            for (int j = 0; j < len; j++) {
                for (int k = 0; k < v.size(); k++) {
                    v[k]++;
                    if (v[k] > size) {
                        v[k] = 1;
                    }
                }
                count++;
            }
        }
        v.erase(v.begin());
        for (int i = 0; i < v.size(); i++) {
            v[i]--;
        }
        size--;
    }
    
    cout << count << endl;
    return 0;
}