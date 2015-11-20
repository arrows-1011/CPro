#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 35
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
 
int H,W,T;
vector<piii> vec;
 
bool check(int s){
    int now = s;
    for(int i = 0 ; i < (int)vec.size() ; i++){
	if(vec[i].second.first == now){
	    now = vec[i].second.second;
	}else if(vec[i].second.second == now){
	    now = vec[i].second.first;
	}
    }
    return now == T;
}
 
int main(){
    int S;
    bool G[MAX][MAX][MAX];
    char in;
   
    while(cin >> W,W){
	memset(G,false,sizeof(G));
	vec.clear();
	cin >> S >> T >> H; S--; T--;
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W-1 ; j++){
		cin >> in;
		if(in == '1'){
		    if(j > 0){
			G[i][j-1][j] = true;
		    }
		    G[i][j][j+1] = G[i][j+1][j+2] = true;
		    vec.push_back(piii(i,pii(j,j+1)));
		}
	    }
	}
	sort(vec.begin(),vec.end());
	if(check(S)){
	    cout << 0 << endl;
	}else{
	    bool found = false;
	    for(int i = 0 ; i < H ; i++){
		for(int j = 0 ; j < W-1 ; j++){
		    if(G[i][j][j+1]) continue;
		    vector<piii> tmp = vec;
		    vec.push_back(piii(i,pii(j,j+1)));
		    sort(vec.begin(),vec.end());
		    if(check(S)){
			cout << i+1 << " " << j+1 << endl;
			found = true;
			goto end;
		    }
		    vec = tmp;
		}
	    }
	end:;
	    if(!found){
		cout << 1 << endl;
	    }
	}
    }
    return 0;
}
