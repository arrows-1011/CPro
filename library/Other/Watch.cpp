/*
  時計の長針と短針のなす角
 */

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    n %= 12;
    double M = 6 * m;
    double N = (n * 60 + m) * 0.5;
    cout << min(360 - abs(M - N), abs(M - N)) << endl;
    return 0;
}
