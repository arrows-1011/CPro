#include <bits/stdc++.h>
 
using namespace std;
 
class Dice{
private:
    int tmp;
public:
    int d[6];
 
    void rollN(){
	tmp = d[0];
	d[0] = d[1];
	d[1] = d[5];
	d[5] = d[4];
	d[4] = tmp;
    }
    void rollE(){
	tmp = d[0];
	d[0] = d[3];
	d[3] = d[5];
	d[5] = d[2];
	d[2] = tmp;
    }
    void rotation(){
	tmp = d[1];
	d[1] = d[3];
	d[3] = d[4];
	d[4] = d[2];
	d[2] = tmp;
    }
    bool operator < (const Dice &die)const{
	for(int i = 0 ; i < 6 ; i++){
	    if(d[i] != die.d[i]) return d[i] < die.d[i];
	}
	return false;
    }
};
 
int N,ans,p[4];
map<string,int> mp;
vector<Dice> dice[4];
 
int getCost(){
    int res = 0;
    for(int i = 0 ; i < 6 ; i++){
	int cnt[25] = {0}, max = 0;
	for(int j = 0 ; j < N ; j++){
	    cnt[dice[j][p[j]].d[i]]++;
	    max = std::max(max,cnt[dice[j][p[j]].d[i]]);
	}
	res += N-max;
    }
    return res;
}
 
void solve(int x){
    if(x == N){
	ans = min(ans,getCost());
	return;
    }
    for(int i = 0 ; i < (int)dice[x].size() ; i++){
	p[x] = i;
	solve(x+1);
    }
}
 
vector<Dice> make(Dice die){
    vector<Dice> res;
    set<Dice> visited;
    for(int i = 0 ; i < 4 ; i++){
	for(int j = 0 ; j < 4 ; j++){
	    if(!visited.count(die)){
		visited.insert(die);
		res.push_back(die);
	    }
	    die.rollN();
	}
	for(int j = 0 ; j < 4 ; j++){
	    if(!visited.count(die)){
		visited.insert(die);
		res.push_back(die);
	    }
	    die.rollE();
	}
	die.rotation();
    }
    return res;
}
 
int main(){
    Dice in;
    while(cin >> N, N){
	int n = 0;
	mp.clear();
	for(int i = 0 ; i < N ; i++){
	    p[i] = -1;
	    for(int j = 0 ; j < 6 ; j++){
		string s;
		cin >> s;
		if(mp.find(s) != mp.end()){
		    in.d[j] = mp[s];
		}else{
		    mp[s] = n++;
		    in.d[j] = mp[s];
		}
	    }
	    dice[i] = make(in);
	}
	ans = 1e9;
	solve(0);
	cout << ans << endl;
    }
    return 0;
}
