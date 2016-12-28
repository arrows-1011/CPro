#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    while (cin >> N, N) {
        vector<string> w(N);
        vector<int> p(N), s(N);
        for (int i = 0; i < N; i++) {
            cin >> w[i] >> p[i];
            s[i] = w[i].size();
        }
        
        string str;
        cin >> str;
        
        int M = str.size();
        vector<int> dp1(M + 1, -1);
        dp1[0] = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (i + s[j] > M) continue;
                bool poss = 1;
                for (int k = 0; k < s[j]; k++) {
                    if (str[i + k] != w[j][k]) {
                        poss = 0;
                        break;
                    }
                }
                if (poss) {
                    dp1[i + s[j]] = max(dp1[i + s[j]], dp1[i] + p[j]);
                }
            }
        }

        int mn = dp1[M];                
        vector<int> dp2(mn + 1, (1 << 29));
        dp2[0] = 0;
        for (int i = 0; i < mn; i++) {
            for (int j = 0; j < N; j++) {
                if (i + p[j] > mn) continue;
                dp2[i + p[j]] = min(dp2[i + p[j]], dp2[i] + s[j]);
            }
        }
        
        static int tc = 1;
        cout << "Case " << tc++ << ": " << dp2[mn] << endl;
    }        
    return 0;
}
