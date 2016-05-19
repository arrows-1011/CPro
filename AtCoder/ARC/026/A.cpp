#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    int C = min(5, N);
    cout << (N - C) * A + C * B << endl;
    return 0;
}
