#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main()
{
    string S;
    cin >> S;
    
    int N = S.size();
    vector<ll> sumc(N + 1), sumw(N + 1);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'c') {
            sumc[i]++;            
        }
        sumc[i + 1] += sumc[i];
    }

    for (int i = N - 1; i > 0; i--) {
        if (S[i] == 'w') {
            sumw[i]++;
        }
        sumw[i - 1] += sumw[i];
    }
    
    ll res = 0;
    for (int i = 1; i < N - 1; i++) {
        if (S[i] == 'w') {
            res += sumc[i - 1] * sumw[i + 1];
        }
    }
    cout << res << endl;
    return 0;
}
