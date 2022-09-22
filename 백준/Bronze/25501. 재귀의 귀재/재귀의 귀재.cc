#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int a = 0;
int isPalindrome(string s, int l, int r) {
    while (true) {
        a+=1;
        if (l >= r) {
            return 1;
        } else if (s[l] != s[r]) {
            return 0;
        }
        else {
            l += 1;
            r -= 1;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int b = isPalindrome(str, 0, str.size() - 1);
        printf("%d %d\n", b,  a);
        a = 0;
    }

    return 0;
}