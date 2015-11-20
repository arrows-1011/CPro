#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1e9
 
int t,ans,size,diff;
vector<int> a,path;
map<int,int> mp;
 
int calc(int idx,int N){
    int res = 0, p = 1;
    for(int i = N-1 ; i >= idx ; i--){
	res += a[i]*p;
	p *= 10;
    }
    return res;
}
 
void solve(int idx,int val,vector<int> &v){
    if(idx == size){
	if(val > t) return;
	if(t-val <= diff){
	    diff = t-val;
	    ans = val; mp[ans]++;
	    path = v;
	}
	return;
    }
 
    for(int i = 1 ; i <= size ; i++){
	if(idx + i > size) continue;
	int c = calc(idx,idx+i);
	v.push_back(c);
	solve(idx+i,val+c,v);
	v.pop_back();
    }
}
 
int main(){
    int num;
    while(cin >> t >> num, (t | num)){
	mp.clear(); a.clear(); 
	diff = ans = INF;
	for(int i = 0 ; ; i++){
	    if(num == 0) break;
	    a.push_back(num%10);
	    num /= 10;
	}
	reverse(a.begin(),a.end());
	size = a.size();
	vector<int> v;
	solve(0,0,v);
	if(diff == INF){
	    cout << "error" << endl;
	}else{
	    if(mp[ans] != 1){
		cout << "rejected" << endl;
	    }else{
		cout << ans;
		for(int i = 0 ; i < (int)path.size() ; i++){
		    cout << " " << path[i];
		}
		cout << endl;
	    }
	}
    }
    return 0;
}
