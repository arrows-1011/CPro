#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    cout << (int)ceil(N / 2.0) * (int)ceil(M / 2.0) << endl;
    return 0;
}
