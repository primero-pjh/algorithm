//2021-11-09
#include<iostream>
#include<vector>
using namespace std;

int n;
int sum = 1;

int repeat(int a) {

    sum *= a;
    return 0;
}

int main()
{
    cin >> n;
    while (n != 0) {
        repeat(n);
        n -= 1;
    }
    cout << sum;
    return 0;
}