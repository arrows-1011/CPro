#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
    int N,M;
    ll X,Y;
    cin >> N >> M >> X >> Y;
    vector<ll> a(N),b(M);
    for(int i = 0 ; i < N ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < M ; i++){
        cin >> b[i];
    }
    int res = 0, t = 0;
    ll tim = 0;
    while(true){
        if(t == 0){
            auto x = lower_bound(a.begin(), a.end(), tim);
            if(x == a.end()) break;
            tim = *x + X; t = 1;
        }else{
            auto y = lower_bound(b.begin(), b.end(), tim);
            if(y == b.end()) break;
            res++;
            tim = *y + Y; t = 0;
        }
    }
    cout << res << endl;
    return 0;
}
