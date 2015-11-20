#include <iostream>
#include <cstdio>

using namespace std;
 
int main(){
    double n,s[10];
     
    while(cin >> n){
        double ans = 0.0;
        s[0] = n;
         
        for(int i = 1 ; i < 10 ;i++){
            if((i+1)%2==0) s[i] = 2.0*s[i-1];
            else s[i] = s[i-1] / 3.0;
        }
        for(int i = 0 ; i < 10 ; i++) ans += s[i];
        printf("%.8f\n" ,ans);
    }
    return 0;
}
