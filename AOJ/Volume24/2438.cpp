#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 50001
#define INF 1e9
 
class YAML{
public:
    string s;
    int state;
    vector<string> next;
};
 
vector<int> space;
YAML yaml[MAX];
 
int getState(string &str,int d,vector<string> &v){
    string now = str.substr(d);
    string s,t;
    int x = -1;
    for(int i = 0 ; i < (int)now.size() ; i++){
	if(now[i] == ':'){ x = d+i+2; break; }
	s += now[i];
    }
    v.push_back(s);
    if(x < (int)str.size()){
	t = str.substr(x);
	v.push_back(t);
	return 1;
    }
    return 0;
}
 
vector<string> make_graph(int cur,int sp){
    int len = space.size();
    vector<string> res;
    if(cur == len || yaml[cur].state == 1) return res;
    int now = cur;
    while(true){
	if(now == len || sp > space[now]) break;
	if(space[now] == INF){ now++; continue; }
	if(sp == space[now]){
	    res.push_back(yaml[now].s);
	    cur = now;
	}else if(sp < space[now]){
	    if(yaml[cur].next.size() == 0){
		yaml[cur].next = make_graph(now,space[now]);
	    }
	}
	now++;
    }
    return res;
}
 
int main(){
    int idx = 1;
    string order,in;
    map<string,int> mp;
    space.push_back(-1);
    yaml[0].s = "->";
    cin >> order; cin.ignore();
    while(getline(cin,in)){
	int cnt = 0;
	for(int i = 0 ; i < (int)in.size() ; i++){
	    if(in[i] == ' '){
		cnt++;
	    }else{ break; }
	}
	space.push_back(cnt);
	vector<string> v;
	yaml[idx].state = getState(in,cnt,v);
	yaml[idx].s = v[0];
	mp[yaml[idx].s] = idx;
	if(yaml[idx].state == 1){
	    yaml[idx].state = 0;
	    yaml[idx].next.push_back(v[1]);
	    idx++;
	    yaml[idx].s = v[1];
	    yaml[idx].state = 1;
	    mp[yaml[idx].s] = idx;
	    space.push_back(INF);
	}
	idx++;
    }
    yaml[0].next = make_graph(1,space[1]);
    string t;
    vector<string> strs;
    for(int i = 0 ; i < (int)order.size() ; i++){
	if(order[i] == '.'){
	    if(!t.empty()){ strs.push_back(t); }
	    t.clear();
	}else{
	    t += order[i];
	}
    }
    strs.push_back(t);
    int now = 0,len = strs.size();
    bool found = true;
    for(int i = 0 ; i < len ; i++){
	vector<string> vec = yaml[now].next;
	bool ok = false;
	for(int j = 0 ; j < (int)vec.size() ; j++){
	    if(vec[j] == strs[i]){
		ok = true;
		break;
	    }
	}
	now = mp[strs[i]];
	if(!ok){
	    found = false;
	    break;
	}
    }
    int size = yaml[now].next.size();
    if(!found || size == 0){
	cout << "no such property" << endl;
    }else{
	if(size != 1){
	    cout << "object" << endl;
	}else{
	    string ans = yaml[now].next[0];
	    if(yaml[mp[ans]].state == 1){
		cout << "string \"" << ans << "\"" << endl;
	    }else{
		cout << "object" << endl;
	    }
	}
    }
    return 0;
}
