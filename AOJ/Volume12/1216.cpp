#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-7
#define equals(a,b) (fabs(a-b) < EPS)
 
struct Point{
    double x,y,z;
 
    double getDist(const Point &p){
	return sqrt(pow(x-p.x,2)+pow(y-p.y,2)+pow(z-p.z,2));
    }
};
 
int main(){
    int Tc,N;
    double QR,RP,PQ;
    cin >> Tc;
    while(Tc--){
	cin >> QR >> RP >> PQ >> N;
	Point p[N];
	for(int i = 0 ; i < N ; i++){
	    cin >> p[i].x >> p[i].y >> p[i].z;
	}
	double qr,rp,pq;
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < N ; j++){
		if(i == j) continue;
		for(int k = 0 ; k < N ; k++){
		    if(i == k || j == k) continue;
		    qr = p[j].getDist(p[k]);
		    rp = p[k].getDist(p[i]);
		    pq = p[i].getDist(p[j]);
		    if(equals(QR/qr,RP/rp) && equals(RP/rp,PQ/pq)){
			cout << i+1 << " " << j+1 << " " << k+1 << endl;
			goto end;
		    }
		}
	    }
	}
    end:;
    }
    return 0;
}
