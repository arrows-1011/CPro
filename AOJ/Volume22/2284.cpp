#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
  
using namespace std;
  
#define MAX 10000
#define INF 1e9
typedef pair<int,int> P;
int ans, N;
vector<P> vec[MAX];
int dp[100][100]; 
 
int dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}
 
int getNum(string &s){
    stringstream ss(s);
    int res;
    ss >> res;
    return res;
}
  
int main(){
    int W, H;
  
    while(cin >> W >> H, (W | H)){
	string in;
	int gx, gy, max = 0;
	for(int i = 0 ; i < MAX ; i++){
	    vec[i].clear();
	}
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> in;
		if(in == ".") continue;
		if(in == "S"){
		    vec[0].push_back(P(i,j));
		}else if(in == "G"){
		    gx = i, gy = j;
		}else{
		    int num = getNum(in);
		    max = std::max(max, num);
		    vec[num].push_back(P(i,j));
		}
	    }
	}
	vec[max+1].push_back(P(gx,gy));
	ans = INF; N = max+2;
	fill(dp[0],dp[H],INF);
	for(int i = 0 ; i < N-1 ; i++){
	    for(int j = 0 ; j < vec[i+1].size() ; j++){
		for(int k = 0 ; k < vec[i].size() ; k++){
		    int bx = vec[i][k].first;
		    int by = vec[i][k].second;
		    int nx = vec[i+1][j].first;
		    int ny = vec[i+1][j].second;
		    if(dp[bx][by] == INF) dp[bx][by] = 0;
		    dp[nx][ny] = min(dp[nx][ny],dp[bx][by] + dist(bx,by,nx,ny));;
		}
	    }
	}
	cout << dp[gx][gy] << endl;
    }
    return 0;
}
