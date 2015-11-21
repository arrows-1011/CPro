/*
  N個の辺から
  四面体の体積を求める.
*/

#include <bits/stdc++.h>

using namespace std;

bool isTri(double a,double b,double c){
    if(c < a+b && a < b+c && b < c+a){
	return true;
    }
    return false;
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
    if(!isTri(v[0],v[1],v[3])){ return 0.0; }
    if(!isTri(v[0],v[2],v[5])){ return 0.0; }
    if(!isTri(v[1],v[2],v[4])){ return 0.0; }
    if(!isTri(v[3],v[4],v[5])){ return 0.0; }
    return calc(v);
}

