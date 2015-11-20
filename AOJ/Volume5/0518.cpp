#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
  
typedef pair<int,int> P;
 
typedef struct{
    int x,y;
} Point; 
 
int dist(P a){
    return a.first*a.first+a.second*a.second;
}
  
int main(){
    int n;
  
    while(cin >> n ,n){
	Point a;
	vector<P> v;
  
	for(int i = 0 ; i < n ; i++){
	    cin >> a.x >> a.y;
	    v.push_back(P(a.x,a.y));
	}  
  
	sort(v.begin(),v.end());
  
	int ans = 0;
 
	for(int i = 0 ; i < n-1 ; i++){
	    for(int j = i + 1 ; j < n ; j++){
		P b,c,d;
     
		b.first = v[i].first - v[j].first;
		b.second = v[i].second - v[j].second;
     
		c.first = v[i].first - b.second;
		c.second = v[i].second + b.first;
		d.first = v[j].first - b.second;
		d.second = v[j].second + b.first;
 
		if(binary_search(v.begin(),v.end(),c) && binary_search(v.begin(),v.end(),d)){
		    ans = max(ans,dist(b));
		}   
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
