#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<double> R(N);
    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }
    sort(R.begin(), R.end());
    double rate = 0;
    for (int i = N-K; i < N; i++) {
        rate = (rate + R[i]) / 2;
    }
    printf("%.8f\n", rate);
    return 0;
}
