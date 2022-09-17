//2022-08-31
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

string calc(string str) {
    vector<int> v;
    vector<char> s;
    string value = "";
    for (int i = 0; i < str.size(); i++) {
        
        if (str[i] == '+' || str[i] == '-') {
            v.push_back(stoi(value));
            value = "";
            s.push_back(str[i]);
        }
        else {
            value += str[i];
            if (i == str.size() - 1) {
                v.push_back(stoi(value));
            }
        }
    }
    int sum = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (s[i-1] == '+') {
            sum += v[i];
        }
        else {
            sum -= v[i];
        }
    }

    return to_string(sum);
}

int main() {
    string str;
    string abc;
    bool _bool = false;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '-') {
            if (_bool) {
                abc.push_back(')');
                i--;
                _bool = !_bool;
            }
            else {
                abc.push_back(str[i]);
                abc.push_back('(');
                _bool = !_bool;
            }

        }
        else {
            abc.push_back(str[i]);
        }

    }

    vector<int> v;
    vector<char> s;
    bool is_start = false;
    string value = "";


    if (_bool) {
        abc.push_back(')');
    }

    string in_value = "";
    string res = "";
    string out_value = "";
    for (int i = 0; i < abc.size(); i++) {
        if (is_start == false) {
            if (abc[i] == '+' || abc[i] == '-') {
                res.push_back(abc[i]);
            }
            else if (abc[i] == '(') {
                is_start = true;
            }
            else if (abc[i] == ')') {
            }
            else {
                res.push_back(abc[i]);
            }
        }
        else {
            if (abc[i] == '+' || abc[i] == '-') {
                value.push_back(abc[i]);
            }
            else if (abc[i] == '(') {
            }
            else if (abc[i] == ')') {
                res += calc(value);
                value = "";
                is_start = false;
            }
            else {
                value.push_back(abc[i]);
            }
        }
    }
    cout << calc(res) << endl;


    return 0;
}