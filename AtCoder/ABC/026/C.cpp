#include <bits/stdc++.h>
 
using namespace std;
 
struct Data{
    int par,sal;
};
 
int main(){
    int N;
    cin >> N;
    vector<int> B(N-1);
    for(int i = 0 ; i < N-1 ; i++){
	cin >> B[i]; B[i]--;
    }
    vector<int> G[30];
    int p[30]; memset(p,-1,sizeof(p));
    for(int i = 0 ; i < N-1 ; i++){
	G[B[i]].push_back(i+1);
	p[i+1] = B[i];
    }
    p[0] = 0;
    vector<Data> per(N);
    for(int i = 0 ; i < N ; i++){
	per[i].par = -1;
	per[i].sal = -1;
    }
    bool visited[30] = {false};
    for(int i = 0 ; i < N ; i++){
	if(G[i].size() == 0){
	    visited[i] = true;
	    per[i].par = p[i];
	    per[i].sal = 1;
	}
    }
    bool update = true;
    while(update){
	update = false;
	for(int i = 0 ; i < N ; i++){
	    bool check = true;
	    int size = G[i].size();
	    if(visited[i]) continue;
	    for(int j = 0 ; j < size ; j++){
		if(per[G[i][j]].par == -1){
		    check = false;
		    break;
		}
	    }
	    if(check){
		visited[i] = true;
		update = true;
		int mini = 1e9, maxi = 0;
		for(int j = 0 ; j < size ; j++){
		    mini = min(mini,per[G[i][j]].sal);
		    maxi = max(maxi,per[G[i][j]].sal);
		}
		per[i].par = p[i];
		per[i].sal = maxi + mini + 1;
	    }
	}
    }
    cout << per[0].sal << endl;
    return 0;
}
