#include <bits/stdc++.h>

using namespace std;

#define MAX 32
#define INF (1<<29)
typedef pair<int, int> pii;

int H, W, S, sum;
int u[MAX][MAX];
pii memo[MAX][MAX][MAX][MAX];

int get_cost(int h1, int w1, int h2, int w2)
{
    int cost = 0;
    for (int i = h1; i <= h2; i++) {
        for (int j = w1; j <= w2; j++) {
            cost += u[i][j];
        }
    }
    return cost;
}

pii solve(int h1, int w1, int h2, int w2)    
{
    pii res = memo[h1][w1][h2][w2];
    if (res.first != -1) {
        return res;
    }
    
    res = pii(1, S - (sum - get_cost(h1, w1, h2, w2)));
    for (int i = h1; i <= h2-1; i++) {
        int c1 = get_cost(h1, w1, i, w2);
        int c2 = get_cost(i+1, w1, h2, w2);
        
        if (sum - c1 <= S && sum - c2 <= S) {
            pii n1 = solve(h1, w1, i, w2);
            pii n2 = solve(i+1, w1, h2, w2);
            pii n = pii(n1.first + n2.first, min(n1.second, n2.second));
            res = max(res, n);
        }        
    }

    for (int i = w1; i <= w2-1; i++) {
        int c1 = get_cost(h1, w1, h2, i);
        int c2 = get_cost(h1, i+1, h2, w2);
        
        if (sum - c1 <= S && sum - c2 <= S) {
            pii n1 = solve(h1, w1, h2, i);
            pii n2 = solve(h1, i+1, h2, w2);
            pii n = pii(n1.first + n2.first, min(n1.second, n2.second));
            res = max(res, n);
        } 
    }
    return memo[h1][w1][h2][w2] = res;
}

int main()
{
    while (cin >> H >> W >> S, H) {
        sum = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> u[i][j];
                sum += u[i][j];
                for (int k = 0; k < H; k++) {
                    for (int l = 0; l < W; l++) {
                        memo[i][j][k][l] = pii(-1, -1);
                    }
                }
            }
        }
        
        pii res = solve(0, 0, H-1, W-1);
        cout << res.first << " " << res.second << endl;
    }    
    return 0;
}
