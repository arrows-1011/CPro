#include <iostream>

using namespace std;
 
int main(){
    int c1,c2,c3,Cards[10];
     
    while(cin >> c1 >> c2 >> c3){
        for(int i = 0 ; i < 10 ; i++){
            Cards[i] = i+1;
            if(c1 == Cards[i]) Cards[i] = 0;
            if(c2 == Cards[i]) Cards[i] = 0;
            if(c3 == Cards[i]) Cards[i] = 0;
        }
         
        int cnt = 0;
        int tc = c1 + c2;
         
        for(int i = 0 ; i < 10 ; i++){
            if(Cards[i]==0) continue;
             
            if(Cards[i]+tc <= 20) cnt++;
        }
        if(cnt >= 4) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
