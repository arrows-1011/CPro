#include <iostream>
#include <vector>

using namespace std;

bool checkBreak(int T,int L){
    if(T <= 0 || T > L) return 1;
    return 0;
}

int main(){
    int N,T,H,L;
    cin >> N >> T >> H >> L;
    vector<int> t(N),h(N);
    for(int i = 0 ; i < N ; i++){
        cin >> t[i] >> h[i];
    }
    int p = 0,coin = 0;
    vector<bool> flg(N,0);
    while(1){
        if(t[p] > 0){
            t[p]--; T++;
            coin += 10;
        }else{
            h[p]--; H++;
            coin += 100;
        }
        if(coin >= 90){
            coin -= 90;
            t[p] += coin/10;
            T -= coin/10;
            coin = 0;
        }
        if(checkBreak(T,L) || flg[p]) break;
        if(t[p] == 0 && h[p] == 0){
            flg[p] = 1;
        }
        p = (p + 1) % N;
    }
    cout << p+1 << endl;
    return 0;
}
