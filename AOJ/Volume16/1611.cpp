#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 334;
constexpr int INF = (1 << 29);

int memo[MAX][MAX];
vector<int> w;

int rec(int L, int R)
{
    int &res = memo[L][R];
    if (res != -1) return res;
    if (L >= R) return (res = 0);
    
    res = -INF;
    
    if (abs(w[L] - w[R]) <= 1) {
        int r = rec(L + 1, R - 1);
        if (r == (R - 1) - (L + 1) + 1) {
            res = max(res, r + 2);
        }
    }
    
    for (int i = L; i <= R; i++) {
        res = max(res, rec(L, i) + rec(i + 1, R));
    }   
    return res;
}

int main()
{
    int N;
    while (cin >> N, N) {
        w.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> w[i];
        }
        
        memset(memo, -1, sizeof(memo));
        cout << rec(0, N - 1) << endl;
    }
    return 0;
}
