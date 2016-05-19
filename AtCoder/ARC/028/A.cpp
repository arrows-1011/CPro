#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, A, B, p = 1;
    cin >> N >> A >> B;
    while (N > 0) {
        p ^= 1;
        N -= (p == 0 ? A : B);
    }
    cout << (p == 0 ? "Ant" : "Bug") << endl;
    return 0;
}
