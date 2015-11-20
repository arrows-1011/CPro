#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> Vec;
typedef pair<Vec,int> P;
 
bool check(Vec &v){
    for(int i = 0 ; i < 32 ; i++){
	if((i+1) % 8 == 0) continue;
	if((i/8+1)*10+i%8+1 != v[i]) return false;
    }
    return true;
}
 
int bfs(Vec &start,Vec &space){
    queue<P> Q;
    queue<Vec> S;
    Q.push(P(start,0));
    S.push(space);
    set<Vec> visited;
    visited.insert(start);
 
    while(!Q.empty()){
	P p = Q.front(); Q.pop();
	Vec s = S.front(); S.pop();
	if(check(p.first)) return p.second;
     
	for(int i = 0 ; i < 4 ; i++){
	    if(p.first[s[i]-1] % 10 == 7) continue;
	    for(int j = 0 ; j < 32 ; j++){
		if(p.first[s[i]-1]+1 == p.first[j]){
		    swap(p.first[s[i]],p.first[j]);
		    int tmp = s[i]; s[i] = j;
		    if(!visited.count(p.first)){
			visited.insert(p.first);
			Q.push(P(p.first,p.second+1));
			S.push(s);
		    }
		    s[i] = tmp;
		    swap(p.first[s[i]],p.first[j]);
		}
	    }
	}
    }
    return -1;
}
 
int main(){
    int Tc;
    cin >> Tc;
    while(Tc--){
	Vec v(32),space;
	for(int i = 0 ; i < 32 ; i++){
	    if(i % 8 != 0){
		cin >> v[i];
		if(v[i]%10 == 1){
		    v[i] = 0;
		    space.push_back(i);
		}
	    }else{
		v[i] = (i/8+1)*10+1;
	    }
	}
	cout << bfs(v,space) << endl;
    }
    return 0;
}
