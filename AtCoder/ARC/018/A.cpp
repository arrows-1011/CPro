#include <bits/stdc++.h>

using namespace std;

int main()
{
    double Height, BMI;
    cin >> Height >> BMI;
    Height /= 100;
    printf("%.10f\n", Height*Height*BMI);
    return 0;
}
