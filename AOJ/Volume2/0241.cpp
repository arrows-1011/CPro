#include <iostream>
 
using namespace std;
 
int main(){
    int N;
 
    while(cin >> N, N){
	int x,y,z,w;
	int x1,y1,z1,w1,x2,y2,z2,w2;
	for(int i = 0 ; i < N ; i++){
	    cin >> x1 >> y1 >> z1 >> w1 >> x2 >> y2 >> z2 >> w2;
	    x = x1*x2-y1*y2-z1*z2-w1*w2;
	    y = x1*y2+x2*y1+z1*w2-w1*z2;
	    z = x1*z2-y1*w2+x2*z1+w1*y2;
	    w = x1*w2+y1*z2-z1*y2+w1*x2;
	    cout << x << " " << y << " " << z << " " << w << endl;
	}
    }
    return 0;
}
