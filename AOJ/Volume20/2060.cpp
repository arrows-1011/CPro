#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX_N 15
  
bool isTri(double a,double b,double c){
    if(c < a+b && a < b+c && b < c+a){
	return true;
    }
    return false;
}
  
double getArea(double a,double b,double c){
    double s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));  
}
  
double S(double x){
    return x*x;
}
  
double calc(vector<double> &v){
    double a = S(v[0])*S(v[4])*(S(v[1])+S(v[2])+S(v[3])+S(v[5])-S(v[0])-S(v[4]));
    double b = S(v[1])*S(v[5])*(S(v[0])+S(v[2])+S(v[3])+S(v[4])-S(v[1])-S(v[5]));
    double c = S(v[2])*S(v[3])*(S(v[0])+S(v[1])+S(v[4])+S(v[5])-S(v[2])-S(v[3]));
    double d = -S(v[0])*S(v[1])*S(v[3])-(S(v[1])*S(v[2]))*S(v[4])-
	S(v[0])*S(v[2])*S(v[5])-S(v[3])*S(v[4])*S(v[5]);
    return sqrt((a+b+c+d)/144.0);
}
  
double getVolume(vector<double> &v){
    if(!isTri(v[0],v[1],v[3])) return 0.0; 
    if(!isTri(v[0],v[2],v[5])) return 0.0; 
    if(!isTri(v[1],v[2],v[4])) return 0.0; 
    if(!isTri(v[3],v[4],v[5])) return 0.0; 
    return calc(v);
}
  
double solve(int S,vector<double> &v,vector<double> &a){
    if(__builtin_popcount(S) == 6){
	return getVolume(v);
    }
    double res = 0;
    for(int i = 0 ; i < (int)a.size() ; i++){
	if((S >> i) & 1) continue;
	v.push_back(a[i]);
	res = max(res,solve(S|(1<<i),v,a));
	v.pop_back();
    }
    return res;
}
  
int main(){
    int N;
    while(cin >> N,N){
	vector<double> a(N),v;
	for(int i = 0 ; i < N ; i++){
	    cin >> a[i];
	}
	printf("%.10f\n",solve(0,v,a));
    }
    return 0;
}
