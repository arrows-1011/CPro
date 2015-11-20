#include <iostream>
#include <vector>

using namespace std;
 
typedef vector<int> V;
 
typedef struct{
    int t,n,m,s;
} Record;
 
int main(){
    int n,m,r,q;
   
    while(cin >> n >> m ,n + m){
	const int MAX = 1260-540;
 
	cin >> r;
	Record d[r];
	vector<V> v(m,V(MAX+1,-1)),cnt(m,V(MAX+1,0));
	int use[1001] = {0};
 
	for(int i = 0 ; i < r ; i++){
	    cin >> d[i].t >> d[i].n >> d[i].m >> d[i].s;
	    if(d[i].s){
		use[d[i].n-1] = d[i].t;
	    }
	    else{
		for(int j = use[d[i].n-1] ; j < d[i].t ; j++){
		    cnt[d[i].m-1][j-540] = 1;
		}
 
	    }
	}
 
	int ts,tt,sn;
	cin >> q;
	for(int i = 0 ; i < q ; i++){
	    cin >> ts >> tt >> sn;
 
	    sn--;
	    bool flg = true;
	    int ans = 0;
	    for(int i = ts ; i < tt ; i++){
		if(cnt[sn][i-540] != 0){
		    ans++;
		}
	    } 
	    cout << ans << endl;
	}
    }
    return 0;
}
