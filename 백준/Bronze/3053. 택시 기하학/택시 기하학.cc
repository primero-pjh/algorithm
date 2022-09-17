 //2021-11-09
#include<iostream>
#include<vector>
#define _USE_MATH_DEFINES
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    int r;
    cin >> r;
    double pi = M_PI;
    vector<double> v; v.clear();
    v.push_back(pow(r, 2) * pi);
    v.push_back(pow(r, 2) * 2);
    printf("%.6lf\n%.6lf", v[0], v[1]);

    return 0;
}