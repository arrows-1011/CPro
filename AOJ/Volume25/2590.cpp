#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 36
#define MAX 1000
 
char getChar(int x){
    return (x < 10 ? x+'0' : x+'A'-10);
}
 
int main(){
    int N,M,Q;
    while(cin >> N >> M >> Q, N){
	string S,B[MAX+1];
	bool sw[MAX+1][MAX_N];
	sw[0][0] = false;
	for(int i = 1 ; i <= Q ; i++){
	    cin >> S >> B[i];
	    for(int j = 0 ; j < N ; j++){
		sw[i][j] = (S[j] == '1' ? !sw[i-1][j] : sw[i-1][j]);
	    }
	}
	string ans;
	for(int i = 0 ; i < M ; i++){
	    bool use[MAX_N];
	    fill(use,use+N,true);
	    for(int j = 1 ; j <= Q ; j++){
		for(int k = 0 ; k < N ; k++){
		    if(!sw[j][k] && B[j][i] == '1' ||
		       sw[j][k] && B[j][i] == '0'){
			use[k] = false;
		    }
		}
	    }
	    bool ok = true;
	    int x = -1;
	    for(int j = 0 ; j < N ; j++){
		if(use[j]){
		    if(x != -1) ok = false;
		    x = j;
		}
	    }
	    ans += (ok ? getChar(x) : '?');
	}
	cout << ans << endl;
    }
    return 0;
}
