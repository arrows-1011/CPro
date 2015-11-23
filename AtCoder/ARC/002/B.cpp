#include <bits/stdc++.h>
 
using namespace std;
 
bool isDiv(double Y,double M,double D){
    double res = Y/M/D;
    int x = res;
    return (res == x);
}
 
bool isLeap(int Y){
    if(Y % 400 == 0) return true;
    if(Y % 100 == 0) return false;
    if(Y % 4 == 0) return true; 
    return false;
}
 
int main(){
    int Y,M,D;
    const int m[13] = {0,32,29,32,31,32,31,32,32,31,32,31,32};
    scanf("%d/%d/%d",&Y,&M,&D);
    while(true){
	if(isDiv(Y,M,D)){
	    printf("%d/%02d/%02d\n",Y,M,D);
	    break;
	}
	D++;
	if((M == 2 && isLeap(Y)+m[M] == D) || (M != 2 && m[M] == D)){
	    M++; D = 1;
	}
	if(M == 13){ M = 1; Y++; }
    }
    return 0;
}
