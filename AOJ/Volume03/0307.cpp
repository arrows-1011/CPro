#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, R, T;
    cin >> N >> R >> T;
    vector<int> p(N), cur(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];        
    }
    
    int res = 0;
    vector<int> e(R), f(R); 
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < N; j++) {
            cur[j] = (cur[j] + p[j]) % R;
            if (i != 0) e[cur[j]]++;
            if (f[cur[j]] > 0) {
                f[cur[j]]--;
            } else {
                res++;
            }
        }
        for (int j = 0; j < R; j++) {
            f[j] += e[j];
            e[j] = 0;
        }
    }
    cout << res << endl;
    return 0;
}
