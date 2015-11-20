#include <bits/stdc++.h>
 
using namespace std;
 
#define prev(x) ((x - 1 + (M+1)) % (M+1))
#define next(x) ((x + 1) % (M+1))
 
int main(){
    int N,M,p;
    cin >> N >> M >> p;
    vector<int> d(M+1);
    for(int i = 0 ; i < M ; i++){
        cin >> d[i];
    }
    d[M] = p;
    for(int i = 0 ; i <= M ; i++){
        d[i] -= p;
        if(d[i] < 0) d[i] += N;
    }
    sort(d.begin(),d.end());
    int res = min(d[prev(0)],N-d[next(0)]);
    for(int i = 1 ; i <= M ; i++){
        int pr = d[prev(i)],ne = d[next(i)];
        int pc = (N-d[i])*2 + pr,nc = d[i]*2+(N-ne);
        res = min(res,pc);
        res = min(res,nc);
    }
    cout << res*100 << endl;
    return 0;
}
