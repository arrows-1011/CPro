#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    const int d1[] = {2, 3, 5, 7, 11, 13};
    const int d2[] = {4, 6, 8, 9, 10, 12};
    int K;
    cin >> K;
    
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (d1[i] * d2[j] == K) {
                cnt++;
            }
        }
    }
    printf("%.15f\n", cnt / 36.0);
    return 0;
}
