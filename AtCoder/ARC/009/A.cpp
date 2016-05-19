#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, a, b, sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        sum += a * b;
    }
    cout << (int)(sum * 1.05) << endl;
    return 0;
}
