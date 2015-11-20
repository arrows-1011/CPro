#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 110
 
bool check(int ant[MAX],int L){
    for(int i = 0 ; i < L ; i++){
	if(ant[i] != 0) return false;
    }
    return true;
}
 
int main(){
    int N,L,p;
    char d;
    while(cin >> N >> L, N){
	int ant[MAX]={0};
	vector<int> tunnel[MAX],id[MAX];
	L--;
	for(int i = 0 ; i < N ; i++){
	    cin >> d >> p;
	    ant[p-1]++;
	    id[p-1].push_back(i+1);
	    tunnel[p-1].push_back((d == 'L' ? 1 : 2));
	}
	int t = 0,last;
	while(!check(ant,L)){
	    vector<int> next[MAX],nid[MAX];
	    last = -1;
	    for(int i = 0 ; i < L ; i++){
		next[i].clear();
		nid[i].clear();
		if(ant[i] && last == -1){
		    last = id[i][0];
		}
	    }
	    for(int i = 0 ; i < L ; i++){
		while(tunnel[i].size()){
		    if(tunnel[i][0] == 1){
			tunnel[i].erase(tunnel[i].begin());
			if(i-1 >= 0){
			    next[i-1].push_back(1);
			    nid[i-1].push_back(id[i][0]);
			    id[i].erase(id[i].begin());
			}
		    }else if(tunnel[i][0] == 2){
			tunnel[i].erase(tunnel[i].begin());
			if(i+1 < L){
			    next[i+1].push_back(2);
			    nid[i+1].push_back(id[i][0]);
			    id[i].erase(id[i].begin());
			}
		    }
		}
	    }
	    for(int i = 0 ; i < L ; i++){
		tunnel[i] = next[i];
		id[i] = nid[i];
		if(tunnel[i].size() == 2){
		    swap(tunnel[i][0],tunnel[i][1]);
		}
		ant[i] = tunnel[i].size();
	    }
	    t++;
	}
	cout << t << " " << last << endl;
    }
    return 0;
}
