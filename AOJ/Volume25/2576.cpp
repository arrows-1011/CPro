#include <iostream>
#include <algorithm>
  
using namespace std;
  
int D,x,y,p[100],ans;
string a[100];
  
void solve(int d,int sum,int pos){
    ans = max(ans,sum);
  
    if(pos == x + y || d == 0){
	return;
    }
  
    int size = a[pos].size();
    if(size == 1){
	if(a[pos] == "D" && d > 0){
	    solve(d-1,sum+p[pos],pos+1);
	}
    }else{
	if(a[pos] == "DD" && d > 1){
	    solve(d-2,sum+p[pos],pos+1);
	} 
    }
  
    solve(d,sum,pos+1);
}
  
int main(){
    cin >> D >> x;
    for(int i = 0 ; i < x ; i++){
	cin >> a[i] >> p[i];
    }
    cin >> y;
    for(int i = x ; i < x + y ; i++){
	cin >> a[i] >> p[i];
    }
  
    solve(D,0,0);
    cout << ans << endl;
    return 0;
}
