#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1e9
typedef long long ll;
typedef vector<ll> Vec;
  
struct State{
    Vec v;
    int sp,cost;
    State(Vec v,int sp,int cost)
	: v(v),sp(sp),cost(cost) {}
    bool operator < (const State &s)const{
	return cost > s.cost;
    }
};
 
int ch,cv;
const int d[4] = {-1,1,-3,3};
 
ll getVal(Vec &v){
    ll res = 0LL;
    for(auto &x : v){
	res *= 9;
	res += x;
    }
    return res;
}
 
int dijkstra(Vec &st,ll target,int sp){
    priority_queue<State> Q;
    Q.push(State(st,sp,0));
    unordered_map<ll,int> mp;
    mp[getVal(st)] = 0;
 
    while(!Q.empty()){
	State s = Q.top(); Q.pop();
	ll val = getVal(s.v);
	if(mp.find(val) != mp.end() && mp[val] < s.cost){
	    continue;
	}
	if(val == target) return mp[val];
	for(int i = 0 ; i < 4 ; i++){
	    int nsp = (s.sp + d[i] + 9) % 9;
	    int cost = (i < 2 ? ch : cv);
	    swap(s.v[nsp],s.v[s.sp]);
	    ll nval = getVal(s.v);
	    if(mp.find(nval) == mp.end() ||
	       mp[val] + cost < mp[nval]){
		mp[nval] = mp[val] + cost;
		Q.push(State(s.v,nsp,mp[nval]));
	    }
	    swap(s.v[nsp],s.v[s.sp]);
	}
    }
    return INF;
}
 
int main(){
    while(cin >> ch >> cv, (ch|cv)){
	int sp;
	Vec s(9),t(9);
	for(int i = 0 ; i < 9 ; i++){
	    cin >> s[i];
	    if(s[i] == 0) sp = i;
	}
	for(int i = 0 ; i < 9 ; i++){
	    cin >> t[i];
	}
	cout << dijkstra(s,getVal(t),sp) << endl;
    }
    return 0;
}
