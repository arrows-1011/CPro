#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll getM(ll H,ll M){
    return H*60+M;
}

int main(){
    ll N,H,M,T;
    cin >> N >> H >> M >> T;
    ll m = getM(H,M) + (N-1)*T;
    m %= 1440;
    cout << m/60 << endl << m%60 << endl;
    return 0;
}
