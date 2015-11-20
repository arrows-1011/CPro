#include <bits/stdc++.h>
  
using namespace std;
 
#define rep(i,n) for(int i = 0 ; i < n ; i++) 
#define MAX 300
typedef pair<int,int> P;
 
class Dice{
private:
    int tmp;
public:
    int d[6];
 
    Dice(){
	rep(i,6){
	    d[i] = i+1;
	}
    } 
 
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
  
    void rollS(){
	tmp = d[0];
	d[0] = d[4];
	d[4] = d[5];
	d[5] = d[1];
	d[1] = tmp;
    }
  
    void rollW(){
	tmp = d[0];
	d[0] = d[2];
	d[2] = d[5];
	d[5] = d[3];
	d[3] = tmp;
    }
 
    void rotation(){
	tmp = d[1];
	d[1] = d[3];
	d[3] = d[4];
	d[4] = d[2];
	d[2] = tmp;
    }
 
    void change(int top,int front){
	rep(i,3){
	    rollN();
	    if(top == d[0]){
		break;
	    }
	    rollW();
	    if(top == d[0]){
		break;
	    }
	}
	rep(i,3){
	    if(front == d[1]){
		break;
	    }
	    rotation();
	}
    }
};
 
map<P,int> num;
int field[MAX][MAX];
 
void init(){
    num.clear();
    for(int i = 0 ; i < MAX ; i++){
	for(int j = 0 ; j < MAX ; j++){
	    field[i][j] = -1;
	}
    }
}
 
bool check(P a, P b){
    return num[a] > num[b];
}
 
int main(){
    int N;
    const int dx[] = {0,1,-1,0};
    const int dy[] = {1,0,0,-1};
    while(cin >> N, N){
	int t, f;
	Dice dice;
	init();
	rep(i,N){
	    int x = 150, y = 150;
	    cin >> t >> f;
	    dice.change(t, f);
	    if(i == 0){
		num[P(y,x)]++;
		field[y][x] = dice.d[0];
	    }else{
		while(true){
		    int pos = 0, max = 0;
		    for(int j = 1 ; j < 5 ; j++){
			if(dice.d[j] < 4) continue;
			int nx = x + dx[j-1];
			int ny = y + dy[j-1];
			if(max < dice.d[j] && check(P(y,x),P(ny,nx))){
			    max = std::max(max,dice.d[j]);
			    pos = j-1;
			}
		    }
		    if(max == 0){
			num[P(y,x)]++;
			field[y][x] = dice.d[0];
			break;
		    }
 
		    x += dx[pos];
		    y += dy[pos];
 
		    switch(pos){
		    case 0:
			dice.rollS();
			break;
		    case 1:
			dice.rollE();
			break;
		    case 2:
			dice.rollW();
			break;
		    case 3:
			dice.rollN();
			break;
		    }
		}
	    }
	}
	int cnt[6] = {0};
	rep(i,MAX){
	    rep(j,MAX){
		if(field[i][j] != -1){
		    cnt[field[i][j]-1]++;
		}
	    }
	}
	rep(i,6){
	    if(i == 5) cout << cnt[i] << endl;
	    else cout << cnt[i] << " ";
	}
    }
 
    return 0;
}
