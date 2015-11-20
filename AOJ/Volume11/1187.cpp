#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_T = 51;
const int MAX_P = 11;
typedef pair<int,int> PP;
typedef pair<PP,int> P;
 
int main(){
    int m,t,p,r,team[MAX_T][MAX_P],judge[MAX_T][MAX_P];
    int mi,ti,pi,ji,accnt[MAX_T];
 
    while(cin >> m >> t >> p >> r , m + t + p + r){
	vector<P> v;
	fill(team[0],team[MAX_T],0);
	fill(judge[0],judge[MAX_T],0);
	fill(accnt,accnt+MAX_T,0);
 
	for(int i = 0 ; i < r ; i++){
	    cin >> mi >> ti >> pi >> ji;
	    if(ji == 0){
		team[ti][pi] += mi + judge[ti][pi];
		accnt[ti]--;
	    }
	    else{
		judge[ti][pi] += 20;
	    }
	}
	int tt[MAX_T] = {0};
	for(int i = 1 ; i < MAX_T ; i++){
	    for(int j = 1 ; j < MAX_P ; j++){
		tt[i] += team[i][j];
	    } 
	}
	for(int i = 1 ; i <= t ; i++){
	    v.push_back(P(PP(accnt[i],tt[i]),-i));
	}
	sort(v.begin(),v.end());
	for(int i = 1 ; i <= v.size() ; i++){
	    if(v[i-1].first.first < v[i].first.first){
		cout << -v[i-1].second;
		if(i != v.size()) cout << ',';
	    }
	    else{
		if(v[i-1].first.second < v[i].first.second){
		    cout << -v[i-1].second;
		    if(i != v.size()) cout << ',';
		}
		else{
		    cout << -v[i-1].second;
		    if(i != v.size()) cout << '=';
		}
	    }
	}
	cout << endl;
    }
    return 0;
}
