#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 51;
typedef pair<int,int> PP;
typedef pair<int,PP> P;
 
int main(){
    int t,p,r,tID,pID,time;
    string judge;
 
    while(cin >> t >> p >> r ,t + p + r){
	int ans[MAX][MAX] = {{0}},pe[MAX][MAX] = {{0}},AC[MAX]={0};
	while(r--){
	    cin >> tID >> pID >> time >> judge;
 
	    if(judge == "CORRECT"){
		ans[tID][pID] += time+pe[tID][pID];
		AC[tID]++;
	    }
	    else{
		pe[tID][pID] += 1200;
	    }
	}
 
	vector<P> v(t);
	for(int i = 0 ; i < t ; i++){
	    for(int j = 0 ; j < p ; j++){
		v[i].second.first += ans[i+1][j+1];
	    }
	    v[i].first = -AC[i+1];
	    v[i].second.second = i+1;
	}
	sort(v.begin(),v.end());
	for(int i = 0 ; i < t ; i++){
	    cout << v[i].second.second << ' ' << -v[i].first 
		 << ' ' << v[i].second.first << endl; 
	}
    }
    return 0;
}
