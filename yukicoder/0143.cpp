#include <bits/stdc++.h>

using namespace std;

int main()
{
    int K, N, F, A, sum = 0;
    cin >> K >> N >> F;
    for (int i = 0; i < F; i++) {
        cin >> A;
        sum += A;
    }
    int res = K * N - sum;
    cout << (res < 0 ? -1 : res) << endl;
    return 0;
}
