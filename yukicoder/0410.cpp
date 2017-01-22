#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    double px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    printf("%.10f\n", (abs(px - qx) + abs(py - qy)) / 2); 
    return 0;
}
