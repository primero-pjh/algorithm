//2022-08-19
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int n = 0;
int main()
{
    scanf("%d", &n);
    map<int, bool> m;
    for (int i = 0; i < n; i++) {
        int a = 0;
        scanf("%d", &a);
        
        if (m.find(a) == m.end()) {
            m[a] = true;
        }
    }
    map<int, bool>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        printf("%d\n", iter->first);
    }

    return 0;
}