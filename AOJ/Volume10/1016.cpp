#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 1001;
 
int V,d;
int v[MAX];
 
void fibo(){
    v[0] = 1,v[1] = 2;
    for(int i = 2 ; i < MAX ; i++){
	v[i] = (v[i-1]+v[i-2])%MAX;
    }
}
 
int main(){
    while(cin >> V >> d){
	fibo();
	sort(v,v+V+1);
	int cnt = 1;
	for(int i = 2; i <= V ; i++){
	    if(v[i-1] + d <= v[i]) cnt++;
	}
	cout << cnt << endl;
    }
    return 0;
}
