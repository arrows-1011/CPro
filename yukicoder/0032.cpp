#include <iostream>

using namespace std;

int main()
{
    int L, M, N;
    cin >> L >> M >> N;
    M += N / 25;
    N = N % 25;
    L += M / 4;
    M = M % 4;
    L = L % 10;
    cout << L + M + N << endl;
    return 0;
}

