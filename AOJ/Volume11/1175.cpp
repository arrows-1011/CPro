#include <bits/stdc++.h>

using namespace std;

#define MAX 24

int N,x[MAX],y[MAX],r[MAX],c[MAX];

int dist(int a,int b){
    return (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]);
}

bool check(int a,int b){
    int d = dist(a,b);
    int add = r[a]+r[b],sub = r[a]-r[b];
    return ((sub*sub < d && d < add*add) || d <= sub*sub);
}

int main(){
    while(cin >> N, N){
        for(int i = 0 ; i < N ; i++){
            cin >> x[i] >> y[i] >> r[i] >> c[i];
        }
        int bit[MAX] = {0};
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < i ; j++){
                if(check(i,j)) bit[i] |= (1<<j);
            }
        }
        vector<bool> dp(1<<N,0);
        dp[(1<<N)-1] = 1;
        int res = 0;
        for(int i = (1<<N)-1 ; i >= 0 ; i--){
            if(dp[i] == 0) continue;
            if(N%2 == 0 && __builtin_popcount(i) % 2 == 1) continue;
            if(N%2 == 1 && __builtin_popcount(i) % 2 == 0) continue;
            for(int j = 0 ; j < N ; j++){
		if(__builtin_popcount(i&bit[j]) > 0) continue;
                for(int k = j+1 ; k < N ; k++){
                    if(c[j] != c[k]) continue;
                    if(__builtin_popcount(i&bit[k]) > 0) continue;
                    int S = i & ~((1<<j) | (1<<k));
                    dp[S] = 1;
                    res = max(res,N-__builtin_popcount(i));
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
