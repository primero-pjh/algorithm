//2022-08-27
#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<vector>
using namespace std;


map<char, vector<int>> m;
int dp[200001];
string input[200001][4];
int main() {
    int N;
    string str;
    cin >> str;
    scanf("%d", &N);
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        char a; char b; int l; int r;
        int arr[200001] = { 0 };
        vector<int> v;
        scanf("%c%c %d %d", &a, &b, &l, &r);
        m[b] = v;
        input[i][0] = b;
        input[i][1] = to_string(l);
        input[i][2] = to_string(r);
    }

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        vector<int> v;
        int count = 0;
        if (str[0] == iter->first) {
            v.push_back(1);
        }
        else {
            v.push_back(0);
        }
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == iter->first) {
                count++;
                v.push_back(v[i - 1] + 1);
            }
            else {
                v.push_back(v[i - 1]);
            }
        }
        m[iter->first] = v;
    }
    for (int i = 0; i < N; i++) {
        char a = input[i][0][0];
        int b = stoi(input[i][1]);
        int c = stoi(input[i][2]);
        if (b != 0) {
            printf("%d\n", m[a][c] - m[a][b-1]);
        }
        else {
            printf("%d\n", m[a][c]);
        }
        
    }

    return 0;
}