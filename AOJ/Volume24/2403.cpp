#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX 45
typedef long long ll;
  
int N, B[MAX], sum[MAX], mx;
ll ng[MAX];

void dfs(ll v, int strength, ll S)
{
    mx = max(mx, strength);
    
    if (v == N || sum[v] + strength <= mx) {
        return;
    }    
    dfs(v+1, strength, S);
    if (!(S >> v & 1) && (ng[v] & S) == 0) {
        dfs(v+1, strength + B[v], S|(1LL<<v));
    }
}
  
int main()
{
    while (cin >> N, N) {
        string A, D;
        int C;
        vector<string> DG[MAX];          
        map<string, int> s2i;
        
        for (int i = 0; i < N; i++) {
            cin >> A >> B[i] >> C;
            s2i[A] = i;
            for (int j = 0; j < C; j++) {
                cin >> D;
                DG[i].push_back(D);
            }
        }
        
        sum[N-1] = B[N-1];
        for (int i = N-2; i >= 0; i--) {
            sum[i] = sum[i+1] + B[i];
        }
        
        for (int i = 0; i < N; i++) {
            int len = DG[i].size();
            ng[i] = 0;
            for (int j = 0; j < len; j++) {
                ll t = s2i[DG[i][j]];
                ng[i] |= 1LL<<t;
            }
        }
        mx = 0;
        dfs(1, B[0], 1<<0);
        cout << mx << endl;
    }
    return 0;
}
