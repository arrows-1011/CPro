#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1001;
typedef pair<int,int> QQ;
typedef pair<int,int> PP;
typedef pair<PP,QQ> P;
 
int main(){
    int n;
 
    while(cin >> n ,n){
	int id,uni,ac,pe;
	int tc[MAX+1];
	fill(tc,tc+MAX,0);
	vector<P> v;
 
	while(n--){
	    cin >> id >> uni >> ac >> pe;
	    v.push_back(P(PP(-ac,pe),QQ(id,uni)));
	} 
	sort(v.begin(),v.end());
 
	int cnt = 0;
	int size = v.size();
	for(int i = 0; i < size ; i++){
	    int u = v[i].second.second;
    
	    if(cnt < 10){
		if(tc[u] < 3){
		    cout << v[i].second.first << endl;
		    cnt++;
		}
	    }
	    else if(cnt < 20){
		if(tc[u] < 2){
		    cout << v[i].second.first << endl;
		    cnt++;
		}
	    }
	    else if(cnt < 26){
		if(tc[u] < 1){
		    cout << v[i].second.first << endl;
		    cnt++;
		}
	    }
	    tc[u]++;
	} 
    }
    return 0;
}
