#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, a, sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        sum += a;
    }
    int v; cin >> v;
    cout << sum - v << endl;
    return 0;
}
