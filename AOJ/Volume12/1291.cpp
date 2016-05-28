#include <bits/stdc++.h>

using namespace std;

#define MAX 5010
#define MAX_N 12
typedef unsigned long long ull;
const ull B = 1000000007ULL;

vector<ull> rolling_hash(string &s)
{
    int N = s.size();
    vector<ull> hash(N+1);
    hash[0] = 0;
    
    for (int i = 0; i < N; i++) {
        hash[i+1] = hash[i] * B + s[i];        
    }
    return hash;
}

int main()
{
    ull p[MAX];
    p[0] = 1;
    for (int i = 0; i < MAX-1; i++) {
        p[i+1] = p[i] * B;
    }

    int N, M;
    while (cin >> N >> M, N) {
        int total = 0, len_e[12];
        string e;
        vector<vector<ull>> hash_e(N);
        for (int i = 0; i < N; i++) {
            cin >> e;
            hash_e[i] = rolling_hash(e);
            total += len_e[i] = e.size();
        }
        string str, t;
        for (int i = 0; i < M; i++) {
            cin >> t;
            str += t;
        }

        int n = str.size(), sum = 0;
        vector<ull> hash_t = rolling_hash(str);
        for (int i = 0; i <= n - total; i++) {
            bool dp[1<<MAX_N] = {};
            dp[0] = 1;
            for (int j = 0; j < (1<<N)-1; j++) {
                if (dp[j] == 0) continue;
                int pos = i;
                for (int k = 0; k < N; k++) {
                    if (j >> k & 1) {
                        pos += len_e[k];
                    }                    
                }
                for (int k = 0; k < N; k++) {
                    if (j >> k & 1) continue;
                    int L = pos, R = pos + len_e[k] - 1;
                    ull h = hash_t[R+1] - hash_t[L] * p[R - L + 1];
                    if (h == hash_e[k][len_e[k]]) {
                        dp[j|(1<<k)] = 1;
                    }
                }
            }
            sum += dp[(1<<N)-1];
        }        
        cout << sum << endl;
    }
    return 0;
}
