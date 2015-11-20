#include <iostream>

using namespace std;
 
int judge(int n){
    int sum = 0 , largest = 0;
     
    for(int i = 2 ; i <= n ; i++){
        if(n%i==0){
            sum += i;//2
            largest = i;
            while(n%i==0){
                n /= i;
            }
        }
    }
    sum -= largest;
    return largest-sum;
}
 
int main(){
    int a,b;
     
    while(cin >> a >> b ,a+b){
        bool flg;
         
        if(judge(a) > judge(b)) flg = true;
        else flg = false;
         
        if(flg) cout << 'a' << endl;
        else cout << 'b' << endl;
    }
 
    return 0;
}
