#include <bits/stdc++.h>
 
using namespace std;

#define MAX 55
#define INF (1<<29)
 
int N, M;
int memo[MAX][MAX][MAX][MAX][2][2];
vector<int> a, b;
 
int get_point(int turn, int al, int ar, int bl, int br)
{
    int ap = 0, bp = 0;   
    bool astop = 0, bstop = 0;
    for (int i = ar-1, j = br-1; i >= al || j >= bl; turn ^= 1) {
        if (turn == 0) {
            if (a[i] == -1) {
                bstop = 1;
            } else if (!astop) {
                ap += a[i];
            }
            i--;
        } else {
            if (b[j] == -1) {
                astop = 1;
            } else if (!bstop) {
                bp += b[j];
            }
            j--;
        }
    }
    return ap - bp;
}
 
int solve(int n, int m, int fn, int fm, int turn, int pass)
{    
    int res = memo[n][m][fn][fm][turn][pass];
    if (res != INF) {
        return res;
    }      
 
    res = (turn == 0 ? -INF : INF);
    
    if (turn == 0) {
        if (pass == 1) {
            res = max(res, 0);
        } else {
            res = max(res, solve(fn, fm, fn, fm, 1, (n == fn && m == fm))
                      + get_point(1, n, fn, m, fm));               
        }
        if (fn < N) {
            res = max(res, solve(n, m, fn+1, fm, 1, 0));
        }
    } else {
        if (pass == 1) {
            res = min(res, 0);
        } else {
            res = min(res, solve(fn, fm, fn, fm, 0, (n == fn && m == fm))
                      + get_point(0, n, fn, m, fm));   
        }
        if (fm < M) {
            res = min(res, solve(n, m, fn, fm+1, 0, 0));
        }        
    }
    
    return (memo[n][m][fn][fm][turn][pass] = res);
}
 
void init()
{
    fill(memo[0][0][0][0][0],
         memo[MAX-1][MAX-1][MAX-1][MAX-1][2], INF);
}
 
int main()
{
    cin >> N >> M;
    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    b.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    init();
    cout << solve(0, 0, 0, 0, 0, 0) << endl;
    return 0;
}
