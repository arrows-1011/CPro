#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-8
typedef complex<double> Point;
 
int main(){
    int N;
    while(cin >> N,N){
	Point p[N];
	for(int i = 0 ; i < N ; i++){
	    cin >> p[i].real() >> p[i].imag();
	}
	int res = 1;
	for(int i = 0 ; i < N-1 ; i++){
	    for(int j = i+1 ; j < N ; j++){
		Point np = p[j]-p[i];
		double d = abs(np);
		if(d + EPS > 2.0){ continue; }
		np /= d;
		np *= Point(0,1);
		Point cp = (p[i]+p[j])/2.0;
		Point v = sqrt(1.0-d*d/4.0)*np;
		int cnt = 2;
		Point center = cp + v;
		for(int k = 0 ; k < N ; k++){
		    if(i == k || j == k) continue;
		    Point diff = center-p[k];
		    if(norm(diff) < 1.0 + EPS){
			cnt++;
		    }
		}
		res = max(res,cnt);
	    }
	}
	cout << res << endl;
    }
    return 0;
}
