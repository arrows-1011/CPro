#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000100
typedef long long ll;
 
int main(){
    ll R,C,K,N;
    cin >> R >> C >> K >> N;
    ll RR[MAX],CC[MAX],r[MAX],c[MAX];
    memset(RR,0LL,sizeof(RR));
    memset(CC,0LL,sizeof(CC));
    for(int i = 0 ; i < N ; i++){
	cin >> r[i] >> c[i];
	r[i]--; c[i]--;
	RR[r[i]]++; CC[c[i]]++;
    }
    ll CCNT[MAX];
    memset(CCNT,0,sizeof(CCNT));
    for(int i = 0 ; i < C ; i++){
	CCNT[CC[i]]++;
    }
    ll res = 0LL;
    for(int i = 0 ; i < R ; i++){
	res += CCNT[K-RR[i]];
    }
    for(int i = 0 ; i < N ; i++){
	if(RR[r[i]]+CC[c[i]] == K+1) res++;
	else if(RR[r[i]]+CC[c[i]] == K) res--;
    }
    cout << res << endl;
    return 0;
}
