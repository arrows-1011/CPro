#include <iostream>
#include <algorithm>
#include <vector>
  
using namespace std;

#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define MAX 100
typedef pair<int,int> P;
 
int N,M;
int scene[MAX][MAX];
int s[MAX/2][MAX/2],rotate_s[MAX/2][MAX/2][4];
 
void rotate(){
    rep(i,3){
	rep(j,M){
	    rep(k,M){
		rotate_s[j][k][i+1] = s[M-k-1][j];
	    }
	}
     
	rep(j,M){
	    rep(k,M){
		s[j][k] = rotate_s[j][k][i+1];
	    }
	}
    }
}
 
void solve(){
    vector<P> v;
 
    rep(i,N-M+1){
	rep(j,N-M+1){
 
	    rep(k,4){
		bool flg = true;
		rep(l,M){
		    rep(n,M){
			if(rotate_s[l][n][k] == -1){
			    continue;
			}
 
			if(scene[i+l][j+n] != rotate_s[l][n][k]){
			    flg = false;
			    goto next;
			}
		    }
		}
	    next:;
		if(flg){
		    rep(l,M){
			bool found = false;
			rep(n,M){
			    if(rotate_s[l][n][k] != -1){
				v.push_back(P(i+l+1,j+n+1));
				found = true;
				break;
			    }
			}
			if(found){
			    break;
			}
		    }
		}
	    }
 
	}
    }
 
    sort(v.begin(),v.end());
 
    if(!v.size()){
	cout << "NA" << endl;
    }else{
	cout << v[0].second << " " << v[0].first << endl;
    }
}
 
int main(){
    while(cin >> N >> M , (N | M)){
	rep(i,N){
	    rep(j,N){
		cin >> scene[i][j];
	    }
	}
 
	rep(i,M){
	    rep(j,M){
		cin >> s[i][j];
		rotate_s[i][j][0] = s[i][j];
	    }
	}
	rotate();
	solve();
    }
    return 0;
}
