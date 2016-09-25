#include <bits/stdc++.h>
 
using namespace std;
 
#define INF (1<<29)
 
int a[10][10], res;
 
void dfs(int n, int S, int cost,
        vector<int> &p, vector<int> &pos)
{
    if (S == (1<<n)-1) {
        res = min(res, cost);
        return;        
    }
 
    if (res <= cost) return;
     
    for (int i = 0; i < n; i++) {
        if (S >> i & 1) continue;
        int npos = 0;
        for (int j = 0; j < (int)pos.size(); j++) {
            npos = max(npos, pos[j] + a[p[j]][i]);
        }
        p.push_back(i);
        pos.push_back(npos);
 
        dfs(n, S|(1<<i), npos, p, pos);
         
        p.pop_back();
        pos.pop_back();
    }
 
}
 
int main()
{
    int n;
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = max(a[i][j], a[j][i]);
            }
        }
         
        res = INF;
        vector<int> p, pos;        
        dfs(n, 0, 0, p, pos);
        cout << res << endl;
    }    
    return 0;
}
