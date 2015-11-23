#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ll N,K;
    cin >> N >> K;
    ll p = N*N*N;
    ll t = (N-K)*(K-1)*6 + (N-1)*3 + 1;
    printf("%.15f\n",(double)t/p);
    return 0;
}
