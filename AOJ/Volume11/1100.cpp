#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define MAX 51
typedef pair<double,double> P;
 
int main(){
    int n,t = 1;
 
    while(cin >> n,n){
	vector<P> v;
	double ans = 0, x ,y;
	for(int i = 0 ; i < n ; i++){
	    cin >> x >> y;
	    v.push_back(P(x,y));
	}  
	for(int i = 1; i < n+1 ; i++){
	    ans += (v[i%n].first-v[i-1].first)*(v[i%n].second+v[i-1].second);
	}
	ans /= 2.0;
	printf("%d %.1f\n" ,t++ ,abs(ans));
    }
    return 0;
}
