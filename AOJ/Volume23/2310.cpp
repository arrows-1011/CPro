#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000
#define INF 1e9
typedef pair<double,int> P;
 
int H,W;
 
double make(int x,int y){
    if(x == 0) return INF;
    return (double)y / x;
}
 
int pat(char a,char b,char c,char d){
    if(a == '.' && b == '#' && 
       c == '#' && d == '#'){
	return 1;
    }
    if(a == '#' && b == '.' && 
       c == '.' && d == '.'){
	return 1;
    }
    if(a == '.' && b == '.' && 
       c == '.' && d == '#'){
	return -1;
    }
    if(a == '#' && b == '#' && 
       c == '#' && d == '.'){
	return -1;
    }
  
    return 0;
}
 
int main(){
    string in;
    char a[MAX][MAX];
 
    for(int i = 0 ; i < MAX ; i++){
	for(int j = 0 ; j < MAX ; j++){
	    a[i][j] = '.';
	}
    }
 
    cin >> H >> W;
    for(int i = H ; i > 0 ; i--){
	cin >> in;
	for(int j = 1 ; j <= W ; j++){
	    a[i][j] = in[j-1];
	}
    }
 
    vector<P> v;
    for(int i = 0 ; i <= H ; i++){
	for(int j = 0 ; j <= W ; j++){
	    char u1 = a[i+1][j],u2 = a[i+1][j+1];
	    char u3 = a[i][j],u4 = a[i][j+1];
	    int n = pat(u1,u2,u3,u4);
 
	    if(n != 0){
		double r = make(j,i);
		v.push_back(P(r,n));
	    }
	}
    }
 
    sort(v.begin(),v.end());
    int len = (int)v.size(),ans = 1,sum = 1;
    for(int i = 0 ; i < len ; i++){
	sum += v[i].second;
	ans = max(ans,sum);
    }
    cout << ans << endl;
    return 0;
}
