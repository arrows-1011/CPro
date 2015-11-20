#include <iostream>
#include <algorithm>

using namespace std;

#define INF 9999999
#define MAX 101
 
int main(){
    int n,m,s,g1,g2,d[MAX+1][MAX+1],a,b,c;
    while(cin >> n >> m >> s >> g1 >> g2 , n+m+s+g1+g2){
        fill(d[0],d[MAX],INF);
        for(int i = 0 ; i < m ; i++){
            cin >> a >> b >> c;
            d[a][b] = c;
        }
         
        for(int k = 1 ; k <= n ; k++)
            for(int i = 1 ; i <= n ; i++)
                for(int j = 1 ; j <= n ; j++)
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
         
        int res = INF;
        for(int i = 1 ; i <= n ; i++){
            d[i][i] = 0;
            res = min(res,d[s][i]+d[i][g1]+d[i][g2]);
        }
        cout << res << endl;
    }
 
    return 0;
}
