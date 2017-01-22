#include <bits/stdc++.h>

using namespace std;

#define MAX 10010

vector<int> make_prime()
{
    vector<int> pv;
    bool prime[MAX];
    fill(prime, prime + MAX, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i < MAX; i++) {
        if (prime[i]) {
            pv.push_back(i);
            for (int j = i * 2; j < MAX; j += i) {
                prime[j] = 0;
            }
        }
    }
    return pv;
}

bool solve(int N)
{
    vector<int> prime = make_prime();
    bool dp[MAX] = {};
    dp[0] = dp[1] = 1;    
    for (int i = 2; i <= N; i++) {
        for (int j: prime) {
            if (i - j >= 0) {
                dp[i] |= !dp[i - j];
            }
        }
    }
    return dp[N];
}

int main()
{
    int N;
    cin >> N;
    cout << (solve(N) ? "Win" : "Lose") << endl;
    return 0;
}
