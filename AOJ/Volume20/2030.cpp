#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int,int> P;
#define p(a,b) (b-a)*(b-a)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
 
int compute(int a,int b,int c,int d){
    int e[4] = {a,b,c,d};
    int res = (1<<29);
 
    rep(i,4){
	rep(j,4){
	    if(i == j) continue;
	    rep(k,4){
		if(i == k || j == k) continue;
		rep(l,4){
		    if(i == l || j == l || k == l) continue;
		    res = min(res,p(e[j],e[i])+p(e[k],e[j])+p(e[l],e[k]));
		}
	    }
	}
    }
  
    return res;
}
 
int main(){
    int a,b;
 
    while(cin >> a >> b , a | b){
	vector<P> c,d;
	for(int i = 1 ; i*i <= a ; i++){
	    if(a % i == 0){
		c.push_back(P(i,a/i));
	    }      
	}
 
	for(int i = 1 ; i*i <= b ; i++){
	    if(b % i == 0){
		d.push_back(P(i,b/i));
	    }
	}
 
	int ans = (1<<29);
	rep(i,(int)c.size()){
	    rep(j,(int)d.size()){
		ans = min(ans,compute(c[i].first,c[i].second,d[j].first,d[j].second));
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
