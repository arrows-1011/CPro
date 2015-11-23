#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int m,VV;
    cin >> m;
    if(m < 100){
	VV = 0;
    }else if(m <= 5000){
	VV = m*10;
    }else if(m <= 30000){
	VV = m+50000;
    }else if(m <= 70000){
	VV = (m-30000)/5+80000;
    }else{
	VV = 89000;
    }
    printf("%02d\n",VV/1000);
    return 0;
}
