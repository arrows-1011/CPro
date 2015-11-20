#include <iostream>
#include <map>

using namespace std;

const int MAX = 26;
int G[MAX][MAX],n,visit[MAX];
string str;
bool flg;
 
void dfs(int pos){
    visit[pos] = 0;
    for(int i = 0 ; i < 26 ; i++){
	if(G[pos][i]&&visit[i]){
	    G[pos][i]--;
	    dfs(i);
	}
    }
}
 
int main(){
    while(cin >> n,n){
	map<char,int> in,out;
	fill(G[0],G[MAX],0);
	fill(visit,visit+MAX,0);
	for(int i = 0 ; i < n ; i++){
	    cin >> str;
	    in[str[0]]++; out[str[str.size()-1]]++;
	    visit[str[0]-'a'] = visit[str[str.size()-1]-'a'] = 1;
	    G[str[0]-'a'][str[str.size()-1]-'a']++;
	}
	flg = false;
	for(char j = 'a' ; j <= 'z'; j++){
	    if(in[j] != out[j]) flg = true;
	}
	if(!flg){
	    dfs(str[str.size()-1]-'a');
	    for(int i = 0 ; i < 26 ; i++){
		if(visit[i]) flg = true;
	    }
	    if(flg) cout << "NG" << endl;
	    else cout << "OK" << endl;
	}
	else cout << "NG" << endl;
    }
    return 0;
}
