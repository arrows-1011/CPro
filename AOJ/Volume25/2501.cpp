#include <bits/stdc++.h>
 
using namespace std;
 
int dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}
 
int main(){
    int n, a, b, c, d, ans = INT_MAX;
 
    cin >> n >> a >> b >> c >> d;
    a--, b--, c--, d--;
    for(int i = 1 ; i < n ; i++){
	ans = min(ans, dist(a%i,a/i,b%i,b/i)+dist(c%i,c/i,d%i,d/i));
    }
    cout << ans << endl;
    return 0;
}
