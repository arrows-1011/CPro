#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 15
 
const string gesture[MAX] = {
    "Rock","Fire","Scissors","Snake","Human","Tree","Wolf","Sponge",
    "Paper","Air","Water","Dragon","Devil","Lightning","Gun"
};
 
vector<int> v;
bool ges[MAX];
 
int solve(){
    int res = -1, N = (int)v.size();
 
    if(N == 1){
	return res;
    } 
 
    for(int i = 0 ; i < N ; i++){
	int win = 0, lose = 0;
	for(int j = 0 ; j < MAX ; j++){
	    if(v[i] == j || !ges[j]){
		continue;
	    }

	    int cnt = 0, pos = v[i];
	    while(true){
		pos++; cnt++;
		if(pos >= MAX){
		    pos = 0;
		}
 
		if(j == pos){
		    if(cnt > 7){
			lose++;
		    }else{
			win++;
		    }
		    break;
		}
	    }
	}
	if(win == N-1){
	    res = v[i];
	    break;
	}
    }
 
    return res;
}
 
int main(){
    int n;
 
    while(cin >> n ,n){
	string str;
	set<string> st;
 
	v.clear();
	memset(ges,false,sizeof(ges));
 
	for(int i = 0 ; i < n ; i++){
	    cin >> str;
	    if(st.count(str)){
		continue;
	    }
	    for(int j = 0 ; j < MAX ; j++){
		if(gesture[j] == str){
		    v.push_back(j);
		    st.insert(str);
		    ges[j] = true;
		    break;
		}
	    }
	}
    
	sort(v.begin(),v.end());
	int ans = solve();
 
	if(ans == -1){
	    cout << "Draw" << endl;
	}else{
	    cout << gesture[ans] << endl;
	}
    }
    return 0;
}
