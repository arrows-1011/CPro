#include <bits/stdc++.h>
 
using namespace std;
 
#define LIMIT 20
 
struct P{
    int y,x;
    P(int y,int x) : y(y),x(x) {}
};
 
int limit;
vector<int> v;
 
P getPos(int x){
    if(x == 0){ return P(0,2); }
    if(1 <= x && x <= 3){ return P(1,x); }
    if(4 <= x && x <= 8){ return P(2,x-4); }
    if(9 <= x && x <= 11){ return P(3,x-8); }
    return P(4,2);
}
 
int getPos(P p){
    if(p.y == 0){
	if(p.x == 2){ return 0; }
	else{ return -1; }
    }
    if(p.y == 1){
	if(1 <= p.x && p.x <= 3){
	    return p.x;
	}else{
	    return -1;
	}
    }
    if(p.y == 2){
	if(0 <= p.x && p.x <= 4){
	    return p.x+4;
	}else{
	    return -1;
	}
    }
    if(p.y == 3){
	if(1 <= p.x && p.x <= 3){
	    return p.x+8;
	}else{
	    return -1;
	}
    }
    if(p.y == 4){
	if(p.x == 2){
	    return 12;
	}else{
	    return -1;
	}
    }
    return -1;
}
 
int getMD(){
    int sum = 0;
    for(int i = 0 ; i < 13 ; i++){
	if(v[i] == 0){ continue; }
	P np = getPos(i);
	P tp = getPos(v[i]);
	sum += abs(np.x-tp.x) + abs(np.y-tp.y);
    }
    return sum;
}
 
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
 
bool dfs(int sp1,int sp2,int step){
    int md = getMD();
    if(md == 0){ return true; }
    if(md + step > limit){
	return false;
    }
    P p[2] = {getPos(sp1),getPos(sp2)};
    for(int i = 0 ; i < 2 ; i++){
	int x = p[i].x, y = p[i].y;
	for(int j = 0 ; j < 4 ; j++){
	    int nx = x + dx[j], ny = y + dy[j];
	    P np(ny,nx);
	    int next = getPos(np);
	    if(next == -1){ continue; }
	    if(i == 0){
		swap(v[sp1],v[next]);
		if(dfs(next,sp2,step+1)){
		    return true;
		}
		swap(v[sp1],v[next]);
	    }else{
		swap(v[sp2],v[next]);
		if(dfs(sp1,next,step+1)){
		    return true;
		}
		swap(v[sp2],v[next]);
	    }
	}
    }
    return false;
}
 
int main(){
    int x;
    while(cin >> x, x != -1){
	int sp[2];
	v.resize(13); v[0] = x;
	for(int i = 1 ; i < 13 ; i++){
	    cin >> v[i];
	}
	for(int i = 0, j = 0 ; i < 13 ; i++){
	    if(v[i] == 0){
		sp[j++] = i;
	    }
	}
	bool found = false;
	for(limit = 0 ; limit <= LIMIT ; limit++){
	    if(dfs(sp[0],sp[1],0)){
		cout << limit << endl;
		found = true;
		break;
	    }
	}
	if(!found){
	    cout << "NA" << endl;
	}
    }
    return 0;
}
