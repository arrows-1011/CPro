#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double A, B, X, Y;
    cin >> A >> B >> X >> Y;
    printf("%.15f\n", (A + B) * min(X / A, Y / B));
    return 0;
}
