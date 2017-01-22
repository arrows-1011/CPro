#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    vector<int> S(6);
    for (int i = 0; i < 6; i++) {
        cin >> S[i];
    }
    sort(S.begin(), S.end());

    double ave = 0;
    for (int i = 1; i < 5; i++) {
        ave += S[i];
    }
    ave /= 4;
    printf("%.2f\n", ave);
    return 0;
}
