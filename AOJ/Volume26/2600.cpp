#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100010
 
int main(){
    int N,W,H;
    int X[MAX],Y[MAX];
    for(int i = 0 ; i < MAX ; i++){
	X[i] = Y[i] = 0;
    }
    cin >> N >> W >> H;
    for(int i = 0 ; i < N ; i++){
	int x,y,w;
	cin >> x >> y >> w;
	X[max(0,x-w)]++;
	Y[max(0,y-w)]++;
	X[min(W,x+w)]--;
	Y[min(H,y+w)]--;
    }
    for(int i = 0 ; i < W ; i++){
	X[i+1] += X[i];
    }
    for(int i = 0 ; i < H ; i++){
	Y[i+1] += Y[i];
    }
    bool can = false, f = true;
    for(int i = 0 ; i < W ; i++){
	if(X[i] == 0){
	    f = false;
	    break;
	}
    }
    can |= f; f = true;
    for(int i = 0 ; i < H ; i++){
	if(Y[i] == 0){
	    f = false;
	    break;
	}
    }
    can |= f;
    cout << (can ? "Yes" : "No") << endl;
    return 0;
}
