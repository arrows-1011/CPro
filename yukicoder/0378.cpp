#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    ll sum = 0;
    ll M = N;
    while (M > 0) {
        sum += M;
        M /= 2;
    }
    cout << N*2 - sum << endl;
    return 0;
}
