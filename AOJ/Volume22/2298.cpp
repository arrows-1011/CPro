#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <ostream>
#include <bitset>
#include <list>
#include <deque>
#include <complex>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <climits>
 
using namespace std;
 
#define MAX_N 201
#define MAX_L 10001
#define INF 1e9
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define FOR(i,a,b) for(int i = a ; i < b ; i++)
#define all(p) (p).begin(),(p).end() 
 
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
 
int N,K,T,U,V,L;
bool road[MAX_L];
 
double getTime(double v){
    return (double)L / v;
}
 
double solve(){
    int speed = 0, carr = 0;
    double res = 0;
 
    rep(i,L){
	if(road[i]){
	    carr++;
	}
	if(speed == 0 && carr > 0){
	    carr--;
	    speed = V*T;
	}
	if(carr > K){
	    carr--;
	    speed = V*T;
	}
	if(speed > 0){
	    speed--;
	    res += 1./ V;
	}else{
	    res += 1./ U;
	}
    }  
    return res;
}
 
int main(){
    int D;
    memset(road,false,sizeof(road));
    cin >> N >> K >> T >> U >> V >> L;
    rep(i,N){
	cin >> D;
	road[D] = true;
    }
    printf("%.8f\n",solve());
    return 0;
}
