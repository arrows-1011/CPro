#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<bool,int> P; 
 
int main(){
    int N;
  
    while(cin >> N, N){
	vector<P> vec;
	bool in;
	for(int i = 0 ; i < N ; i++){
	    int size = vec.size();
       
	    cin >> in;
	    if(((i+1) % 2) == 0){
		if(vec[size-1].first != in){
		    for(int j = size-1 ; j >= 0 ; j--){
			if(vec[j].first == in){
			    break;
			}else{
			    vec[j].first = in;
			}
		    }
		} 
	    }
	    if(i && vec[size-1].first == in){
		vec[size-1].second++;
	    }else{
		vec.push_back(P(in,1));
	    }
	}
	int ans = 0;
	for(int i = 0 ; i < (int)vec.size() ; i++){
	    if(!vec[i].first){
		ans += vec[i].second;
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
