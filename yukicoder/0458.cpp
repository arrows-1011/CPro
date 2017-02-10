#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> primes;
    vector<bool> p(2 * N, 1);
    p[0] = p[1] = 0;
    for (int i = 2; i < 2 * N; i++) {
        if (!p[i]) continue;
        primes.emplace_back(i);
        for (int j = 2 * i; j < 2 * N; j += i) {
            p[j] = 0;
        }
    }
    
    vector<int> dp(N + 1, -1);
    dp[0] = 0;
    
    int M = primes.size();
    for (int i = 0; i < M; i++) {        
        for (int j = N - primes[i]; j >= 0; j--) {
            if (dp[j] == -1) continue;
            dp[primes[i] + j] = max(dp[primes[i] + j], dp[j] + 1);
        }
    }
    
    cout << dp[N] << endl;
    return 0;
}

