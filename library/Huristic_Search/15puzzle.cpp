/*
  15puzzleを解く.
  ただしLIMITは45
*/

#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1e9
 
struct P{
    int x,y;
    P(int x,int y) : x(x),y(y) {}
};
 
vector<int> v;
 
P getPos(int x){
    x--;
    return P(x%4,x/4);
}
 
int getMD(){
    int res = 0;
    for(int i = 0 ; i < 16 ; i++){
	if(v[i] == 0) continue; 
	P tp = getPos(v[i]);
	res += abs(i%4-tp.x) + abs(i/4-tp.y);
    }
    return res;
}
 
int LIMIT;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
 
bool inField(int x,int y){
    return (0 <= x && x < 4 && 0 <= y && y < 4);
}
 
bool solve(int sp,int step,int prev){
    int md = getMD();
    if(md == 0) return true;
    if(md + step > LIMIT){
	return false;
    }
    int x = sp%4,y = sp/4;
    for(int i = 0 ; i < 4 ; i++){
	int nx = x + dx[i],ny = y + dy[i];
	if(abs(i-prev) == 2) continue;
	if(!inField(nx,ny)) continue;
	int nsp = ny*4 + nx;
	swap(v[sp],v[nsp]);
	if(solve(nsp,step+1,i)){
	    return true;
	}
	swap(v[sp],v[nsp]);
    }
    return false;
}
 
int main(){
    int sp = -1;
    v.resize(16);
    for(int i = 0 ; i < 16 ; i++){
	cin >> v[i];
	if(v[i] == 0) sp = i;
    }
    for(LIMIT = 0 ; LIMIT <= 50 ; LIMIT++){
	if(solve(sp,0,INF)){
	    cout << LIMIT << endl;
	    break;
	}
    }
    return 0;
}
