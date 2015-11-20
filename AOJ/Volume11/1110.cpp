#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> Vec;
 
void solve(Vec &s){
    int ans = 20;
    const int dx[8] = {-1,-1,-1,0,0,1,1,1};
    const int dy[8] = {-1,0,1,-1,1,-1,0,1};
    queue<Vec> Q;
    Q.push(s);
    set<Vec> visited;
    visited.insert(s);
    while(!Q.empty()){
	Vec v = Q.front(); Q.pop();
	int size = v.size();
	ans = min(ans,size);
	for(int i = 0 ; i < size ; i++){
	    for(int j = 0 ; j < 8 ; j++){
		Vec next;
		int nx = i%4 + dx[j];
		int ny = i/4 + dy[j];
		if(nx < 0 || ny < 0 || nx >= min(4,size) || ny >= 5) continue;
		if(nx+ny*4 < 0 || nx+ny*4 >= size) continue;
		if(v[i] == v[nx+ny*4]){
		    for(int k = 0 ; k < size ; k++){
			if(i == k || nx+ny*4 == k) continue;
			next.push_back(v[k]);
		    }
		    if(!visited.count(next)){
			visited.insert(next);
			Q.push(next);
		    }
		}
	    }
	}
    }
    cout << ans << endl;
}
 
int main(){
    int Tc;
    cin >> Tc;
    while(Tc--){
	Vec vec(20);
	for(int i = 0 ; i < 20 ; i++){
	    cin >> vec[i];
	}
	solve(vec);
    }
    return 0;
}
