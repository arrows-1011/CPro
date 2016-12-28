#include <iostream>
#include <cstring>

using namespace std;

using ll = long long;
constexpr int MAX = 100;

ll comb[MAX][MAX];

void make_comb()
{
    memset(comb, 0, sizeof(comb));
    comb[0][0] = 1;
    for (int i = 0; i < 65; i++) {
        for (int j = 0; j <= i; j++) {
            comb[i + 1][j]     += comb[i][j];
            comb[i + 1][j + 1] += comb[i][j];
        }
    }
}

void solve(ll N, ll s, ll M, ll n)
{
    while (s < M) {
        ll j = -1;
        for (ll i = n; i <= N; i++) {
            if (s + comb[i][n] >= M) {
                s += comb[i - 1][n];
                j = i;
                break;
            }
        }

        for (int i = 0; i < N - j; i++) {            
            cout << '0';
        }
        
        if (n > 0) {
            cout << '1';
        }

        n--;        
        N = j - 1;
    }

    cout << endl;
}

bool run()
{
    ll N, M;
    cin >> N >> M;
    if (N == 0 && M == 0) {
        return false;
    }

    if (M == 1) {
        cout << string(N, '0') << endl;
        return true;
    }
    
    make_comb();
    
    ll sum = 1;    
    for (ll i = 1; i <= N; i++) {
        sum += comb[N][i];
        if (sum >= M) {
            solve(N, sum - comb[N][i], M, i);
            break;
        }
    }
    return true;
}

int main()
{
    while (run())
        ;    
    return 0;
}
