#include <iostream>
 
using namespace std;
 
struct P{
    int x,y;
};
 
int main(){
    int n,m;
    P p[101];
 
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
	cin >> p[i].x >> p[i].y;
   
    bool flg = true;
    int d = 1,a = 0;
 
    for(int i = 0 ; i < m ; i++){
	int t = -1;
     
	for(int j = 0 ; j < m ; j++){
	    if(p[j].x <= d){
		t = max(t,p[j].y);
	    }
	}
 
	if(t == -1){
	    flg = false;
	    break;
	}
     
	a++;
	d = t+1;
	if(d > n) break;
    }
 
    if(d > n) cout << a << endl;
    else cout << "Impossible" << endl; 
 
    return 0;
}
