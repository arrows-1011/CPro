#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef pair<int,int> PA;
typedef pair<int,PA> P;
 
int cho,che;
char table[8][8];
vector<P> v;
 
const int dx[8] = {0,0,1,1,1,-1,-1,-1};
const int dy[8] = {1,-1,0,-1,1,-1,0,1};
const char ch[3] = {'x','o'};
 
void check(int x,int y,int turn,vector<P> &v){
    char c = ch[turn],d = ch[1-turn];
    int count = 0;
 
    for(int i = 0 ; i < 8 ; i++){
	int cnt = 0;
	int nx = x + dx[i];
	int ny = y + dy[i];
 
	while(true){
	    if(0 > nx || 0 > ny || nx >= 8 || ny >= 8){
		break;
	    }
	    if(table[nx][ny] != d){
		if(table[nx][ny] == c){
		    count += cnt;
		}
		break;
	    }
	    cnt++;
	    nx += dx[i];
	    ny += dy[i];
	}
    }   
 
    if(count == 0) return;
    
    if(turn){
	v.push_back(P(-count,PA(x,y)));
    }else{
	v.push_back(P(-count,PA(-x,-y)));
    }
}
 
void change(P a,int turn){
    char c = ch[turn],d = ch[1-turn];
 
    a.first = -a.first;
 
    if(!turn){
	a.second.first = -a.second.first;
	a.second.second = -a.second.second;
    }
    table[a.second.first][a.second.second] = c;
 
    for(int i = 0 ; i < 8 ; i++){
	int nx = a.second.first + dx[i];
	int ny = a.second.second + dy[i];
	vector<PA> v;
 
	while(true){
	    if(0 > nx || 0 > ny || nx >= 8 || ny >= 8){
		break;
	    }
	    if(table[nx][ny] != d){
		break;
	    }
	    v.push_back(PA(nx,ny));
	    nx += dx[i];
	    ny += dy[i];
	}
 
	if(!(0 > nx || 0 > ny || nx >= 8 || ny >= 8) && table[nx][ny] == c){
	    while(true){     
		if(nx == a.second.first && ny == a.second.second){
		    break;
		}
		table[nx][ny] = c;  
		nx -= dx[i];
		ny -= dy[i];
	    }
	}
    } 
 
    if(turn){
	cho += a.first+1;
	che -= a.first;
    }else{
	cho -= a.first;
	che += a.first+1;
    }
}
 
int main(){
    for(int i = 0 ; i < 8 ; i++){
	for(int j = 0 ; j < 8 ; j++){
	    cin >> table[i][j];
 
	    if(table[i][j] == 'o'){
		cho++;
	    }else if(table[i][j] == 'x'){
		che++;
	    }
	}
    }
 
    //true mami ------ false witch
    bool turn = true;
    int pass = 0;
 
    while(true){
	vector<P> v;
  
	if(pass == 2 || !cho || !che || cho+che == 64){
	    break;
	}
  
	for(int i = 0 ; i < 8 ; i++){
	    for(int j = 0 ; j < 8 ; j++){
		if(table[i][j] == '.'){
		    int n = turn ? 1 : 0;
		    check(i,j,n,v);
		}
	    }
	}  
 
	int size = (int)v.size();
 
	if(size == 0){
	    pass++;
	}else{
	    pass = 0;
	    int n = turn ? 1 : 0;
	    sort(v.begin(),v.end());
	    change(v[0],n);
	}
 
	turn = !turn;
    }
 
    for(int i = 0 ; i < 8 ; i++){
	for(int j = 0 ; j < 8 ; j++){
	    cout << table[i][j];
	}
	cout << endl;
    }
    return 0;
}
