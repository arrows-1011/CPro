#include <iostream>

using namespace std;

int main()
{
    int N, P;
    cin >> N >> P;
    cout << (P == N * P ? "=" : "!=") << endl;
    return 0;
}
