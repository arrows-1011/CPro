#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int A[3], B[3];

    scanf("%d.%d.%d", &A[0], &A[1], &A[2]);
    scanf("%d.%d.%d", &B[0], &B[1], &B[2]);
    
    int sumA = 0, sumB = 0;
    for (int i = 0; i < 3; i++) {
        sumA += A[i] * pow(101, 3 - i);
        sumB += B[i] * pow(101, 3 - i);
    }
    cout << (sumA >= sumB ? "YES" : "NO") << endl;
    return 0;
}
