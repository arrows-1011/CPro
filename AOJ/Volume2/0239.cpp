#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000
 
int main(){
    int N, Num[MAX], P[MAX], Q[MAX], R[MAX], Cal[MAX];
 
    while(cin >> N, N){
	int p, q, r, c;
	for(int i = 0 ; i < N ; i++){
	    cin >> Num[i] >> P[i] >> Q[i] >> R[i];
	    Cal[i] = P[i]*4 + Q[i]*9 + R[i]*4;
	}
 
	vector<int> ans;
	cin >> p >> q >> r >> c;
	for(int i = 0 ; i < N ; i++){
	    if(P[i] <= p && Q[i] <= q && R[i] <= r && Cal[i] <= c){
		ans.push_back(Num[i]);
	    }
	}
	int size = ans.size();
	if(size){
	    for(int i = 0 ; i < size ; i++){
		cout << ans[i] << endl;
	    }
	}else{
	    cout << "NA" << endl;
	}
    }
    return 0;
}
