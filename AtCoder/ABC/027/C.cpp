#include <iostream>

using namespace std;

using ll = long long;

int main()
{
    ll N, dep = 0;
    cin >> N;
    for (ll d = N; d > 0; d /= 2) {
        dep++;
    }
    
    int p = 0;
    ll q[] = {(dep % 2), !(dep % 2)};
    ll num = 1;    
    while (num <= N) {
        if (q[p] == 0) {
            num = num * 2;
        } else {
            num = num * 2 + 1;
        }            
        p ^= 1;
    }    
    cout << (p == 1 ? "Aoki" : "Takahashi") << endl;
    return 0;
}
