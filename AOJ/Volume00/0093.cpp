#include <iostream>
#include <cstdio>

using namespace std;
 
int main(){
    bool tf = false;
    int a,b;
     
    for(;;){
        int flg = 0;
        cin >> a >> b;
        if(a == 0 && b == 0) break;
         
        if(tf) puts("");
        else tf = true;
         
        for( ; a <= b ; a++){
            if(!(a%4)){
                if(!(a%100)){
                    if(!(a%400)){
                        flg = 1;
                        cout << a << endl;
                    }
                }
                else{
                    flg = 1;
                    cout << a << endl;
                }
            }
        }
        if(!flg) cout << "NA" << endl;
    }
    return 0;
}
