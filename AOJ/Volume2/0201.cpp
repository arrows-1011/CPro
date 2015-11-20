#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 200
#define INF INT_MAX
typedef pair<string,int> P;
typedef vector<string> Vec;
 
int N;
vector<P> vec;
 
int cost(Vec v){
    int res = 0;
    for(int i = 0 ; i < (int)v.size() ; i++){
	for(int j = 0 ; j < N ; j++){
	    if(vec[j].first == v[i]){
		res += vec[j].second;
		break;
	    }
	}
    }
    return res;
}
 
int main(){
    int M, K;
 
    while(cin >> N, N){
	map<string,Vec> mp;
	P in; 
	vec.clear();
	for(int i = 0 ; i < N ; i++){
	    cin >> in.first >> in.second;
	    vec.push_back(in);
	}
	
	string str, s, item;
	cin >> M;
	for(int i = 0 ; i < M ; i++){
	    cin >> str >> K;
	    for(int j = 0 ; j < K ; j++){
		cin >> s;
		mp[str].push_back(s);
	    }
	}    
 
	map<string,Vec>::iterator it;
	for(int i = 0 ; i < 2 ; i++){
	    for(it = mp.begin() ; it != mp.end() ; ++it){
		for(int j = 0 ; j < N ; j++){
		    if(vec[j].first == it->first){
			vec[j].second = min(vec[j].second, cost(it->second));
		    }
		}
	    }
	}
	cin >> item;
	int ans = INF;
	for(int i = 0 ; i < N ; i++){
	    if(vec[i].first == item){
		ans = vec[i].second;
		break;
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
