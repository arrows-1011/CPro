#include <bits/stdc++.h>

using namespace std;

int main()
{
    double D, P;
    cin >> D >> P;
    D += D * (0.01 * P);
    cout << (int)D << endl;
    return 0;
}
