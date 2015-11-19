#include <bits/stdc++.h>
  
using namespace std;
 
#define rep(i,n) for(int i = 0 ; i < n ; i++) 
 
class Cube{
private:
    string tmp;
public:
    string d[6];
  
    void rollN(){
	tmp = d[0];
	d[0] = d[1];
	d[1] = d[5];
	d[5] = d[4];
	d[4] = tmp;
    }
  
    void rollW(){
	tmp = d[0];
	d[0] = d[2];
	d[2] = d[5];
	d[5] = d[3];
	d[3] = tmp;
    }
 
    void rotation(){
	tmp = d[1];
	d[1] = d[3];
	d[3] = d[4];
	d[4] = d[2];
	d[2] = tmp;
    }
 
    bool judge(Cube &C){
	rep(i,6){
	    if(d[i] != C.d[i]){
		return false;
	    }
	}
	return true;
    }
 
    bool equals(Cube &C){
	rep(i,3){
	    rollN();
	    if(d[0] == C.d[0]){
		break;
	    }
	    rollW();
	    if(d[0] == C.d[0]){
		break;
	    }
	}
	rep(i,4){
	    if(judge(C)){
		return true;
	    }
	    rotation();
	}
	return false;
    }
};
  
int main(){
    int N;
 
    while(cin >> N, N){
	Cube cube[N];
	rep(i,N){
	    rep(j,6){
		cin >> cube[i].d[j];
	    }
	}   
	int ans = 0;
	bool used[N];
	memset(used, false, sizeof(used));
	rep(i,N-1){
	    for(int j = i+1 ; j < N ; j++){
		if(cube[i].equals(cube[j]) && !used[j]){
		    used[j] = true;
		    ans++;
		}
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
