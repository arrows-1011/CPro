#include <iostream>

using namespace std;

int f(int N, int K)
{
    return 50 * N + 250 * N / (4 + K);
}

int main()
{
    int A, B;
    cin >> A >> B;
    cout << f(A, B) << endl;
    return 0;
}
