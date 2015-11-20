#include <iostream>
 
using namespace std;
 
#define MAX 1000001
#define INF (1<<29)
 
int main(){
    int pos[MAX];
    int x,y;
 
    while(true){
	cin >> x >> y;
	if(x == 0 && y == 0) break;
	fill(pos,pos+MAX,INF);
	int a,b;
	for(int i = 0 ; ; i++){
	    x %= y;
	    if(x == 0){
		a = i;
		b = 0;
		break;
	    }
	    if(pos[x] != INF){
		a = pos[x];
		b = i - pos[x];
		break;
	    }
	    pos[x] = i;
	    x *= 10;
	}
	cout << a << " " << b << endl;
    }
    return 0;
}
