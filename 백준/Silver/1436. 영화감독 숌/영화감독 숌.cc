//2021-11-20
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int arr[10000] = { 0 };

int main()
{
    int n;
    cin >> n;
    vector<int> v; v.clear();
    int i = 666;
    int count = 0;
    while (true) {
        string str = to_string(i);
        if (str.find("666", 0) != string::npos) {
            count++;
        }
        if (count == n) {
            printf("%d", i);
            return 0;
        }
        i++;
    }

    return 0;
}