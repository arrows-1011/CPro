#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1e9
 
class Fraction{
public:;
    double numerator,denominator;
    double div();
};
 
double Fraction::div(){
    return numerator/denominator;
}
 
ostream &operator << (ostream &os,const Fraction &f){
    os << f.numerator << '/' << f.denominator;
    return os;
}
 
int main(){
    double p;
    int n;
    while(cin >> p >> n, p){
	p = sqrt(p);
	Fraction a = (Fraction){-1,1};
	Fraction b = (Fraction){INF,1};
	for(int den = 1 ; den <= n ; den++){
	    int l = 0, r = n+1;
	    while(l < r){
		double mid = (l + r) / 2;
		if(mid < p*den){
		    if(mid/den > a.div()){
			a = (Fraction){mid,den};
		    }
		    l = mid+1;
		}else{
		    r = mid;
		}
	    }
	    l = 0, r = n+1;
	    while(l < r){
		double mid = (l + r) / 2;
		if(mid > p*den){
		    if(mid/den < b.div()){
			b = (Fraction){mid,den};
		    }
		    r = mid;
		}else{
		    l = mid+1;
		}
	    }
	}
	cout << b << " " << a << endl;
    }
    return 0;
}
