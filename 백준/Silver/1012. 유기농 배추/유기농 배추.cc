// 2021-10-23
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<sstream>
using namespace std;

map<string, bool> position;
map<string, int> search;

vector<string> split(string s, string divid) {
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


int left(int start, int end, int index) {
    return 0;
}

int sK(int start, int end, int index) {
    string name = to_string(start) + "," + to_string(end);
    if (position.find(name) != position.end()) {
        if (search.find(name) == search.end()) {
            search[name] = index;
            sK(start, end + 1, index);
            sK(start, end - 1, index);
            sK(start - 1, end, index);
            sK(start + 1, end, index);
        }
    }
    return 0;
}

int top(int start, int end, int index) {

    return 0;
}

int bottom(int start, int end, int index) {

    return 0;
}


int main()
{
    int run = 0;
    cin >> run;
    vector<int>result; result.clear();

    while (run--) {
        int M, N, K;
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++) {
            int x, y;
            vector<int> v; v.clear();

            cin >> x >> y;
            v.push_back(x);
            v.push_back(y);
            position[to_string(x) + "," + to_string(y)] = true;
        }
        map<string, bool>::iterator iter;
        int index = 1;
        for (iter = position.begin(); iter != position.end(); iter++) {
            int a = stoi(split(iter->first, ",")[0]); int b = stoi(split(iter->first, ",")[1]);
            string name = to_string(a) + "," + to_string(b);
            if (search.find(name) != search.end()) {       // 만약 존재한다면
                continue;
            }
            else {
                if (search.find(name) == search.end()) {
                    search[name] = index;
                }
                if (a >= 0 && b + 1 >= 0) sK(a, b + 1, index);
                if (a >= 0 && b - 1 >= 0) sK(a, b - 1, index);
                if (a - 1 >= 0 && b >= 0) sK(a - 1, b, index);
                if (a + 1 >= 0 && b >= 0) sK(a + 1, b, index);
            }
            index++;
        }
        map<string, int>::iterator iter2;
        map<int, bool> count;
        for (iter2 = search.begin(); iter2 != search.end(); iter2++) {
            count[iter2->second] = true;
        }

        result.push_back(count.size());
        count.clear();
        search.clear();
        position.clear();
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    
}