#include <iostream>

using namespace std;

const int MAX = 1001;
 
typedef struct{
    int x,y;
} Point;
 
int main(){
    int T;
 
    cin >> T;
    while(T--){
	int dist = 0;
	int x = 0,y = 0;
	Point p,q;
	p.x = p.y = 0;
 
	while(cin >> q.x >> q.y){
	    if(q.x == 0 && q.y == 0) break; 
	    x += q.x; y += q.y;
 
	    if(dist < (x*x+y*y)){
		p.x = x;
		p.y = y;
		dist = x*x+y*y;
	    }
	    else if(dist == (x*x+y*y) && p.x < x){
		p.x = x;
		p.y = y;
		dist = x*x+y*y;
	    }
	}
	cout << p.x << " " << p.y << endl;
    }
    return 0;
}
