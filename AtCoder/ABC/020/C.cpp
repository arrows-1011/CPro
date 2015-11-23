#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 25
#define INF LLONG_MAX/2
typedef long long ll;
 
ll H,W,T,sx,sy,gx,gy,cnt,cc;
char s[MAX][MAX];
ll d[MAX][MAX];
 
struct P{
    ll d,x,y;
    P(ll d,ll x,ll y) : d(d),x(x),y(y) {}
    bool operator < (const P &p)const{
	if(d != p.d){
	    return d > p.d;
	}
    }
};
 
ll dx[] = {-1,0,1,0};
ll dy[] = {0,-1,0,1};
 
bool c(ll m){
    for(int i = 0 ; i < MAX ; i++){
	for(int j = 0 ; j < MAX ; j++){
	    d[i][j] = INF;
	}
    }
    d[sy][sx] = 0;
    priority_queue<P> Q;
    Q.push(P(0,sx,sy));
    while(!Q.empty()){
	P p = Q.top(); Q.pop();
	ll x = p.x, y = p.y;
	if(d[y][x] < p.d) continue;
	if(x == gx && y == gy) return d[y][x] <= T;
	for(int i = 0 ; i < 4 ; i++){
	    ll nx = x + dx[i], ny = y + dy[i];
	    if(0 <= nx && nx < W && 0 <= ny && ny < H){
		if(s[ny][nx] == '#'){
		    if(d[y][x]+m < d[ny][nx]){
			d[ny][nx] = d[y][x]+m;
			Q.push(P(d[ny][nx],nx,ny));
		    }
		}else{
		    if(d[y][x]+1 < d[ny][nx]){
			d[ny][nx] = d[y][x]+1;
			Q.push(P(d[ny][nx],nx,ny));
		    }
		}
	    }
	}
    }
    return false;
}
 
int main(){
    cin >> H >> W >> T;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> s[i][j];
	    if(s[i][j] == 'S'){
		s[i][j] = '.';
		sx = j; sy = i;
	    }
	    if(s[i][j] == 'G'){
		s[i][j] = '.';
		gx = j; gy = i;
	    }
	}
    }
    ll l = 0LL,r = T,res = 0LL;
    while(r - l > 0){
	ll mid = (l + r) / 2LL;
	if(c(mid)){
	    res = max(res,mid);
	    l = mid+1LL;
	}else{
	    r = mid;
	}
    }
    cout << res << endl;
    return 0;
}
