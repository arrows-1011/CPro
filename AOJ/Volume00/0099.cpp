#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> P;
const int MAX = 1e6;
 
class Point{
public:
    int x,y;
    Point(int x = 0,int y = 0): x(x),y(y){}
};
 
int main(){
    int n,q,a[MAX+1]={0};
    priority_queue<P> Q;
    Point x,y;
 
    cin >> n >> q;
    while(q--){
	cin >> x.x >> x.y;
	a[x.x] += x.y;
	Q.push(P(a[x.x],-x.x));
	while(true){
	    y.x = -Q.top().second;
	    y.y = Q.top().first;
	    if(a[y.x] == y.y){
		cout << y.x << " " << y.y << endl;
		break;
	    }
	    Q.pop();
	}
    }
    return 0;
}
