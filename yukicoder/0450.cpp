#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double vl, vr, d, w;
    cin >> vl >> vr >> d >> w;
    printf("%.15f\n", d * w / (vl + vr));
    return 0;
}
