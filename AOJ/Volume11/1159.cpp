#include <iostream>

using namespace std;

#define MAX 51
 
int main(){
    int n,p,st[MAX];
     
    while(cin >> n >> p){
        bool flg = false;
        if(!n && !p) break;
        fill(st,st+n,0);
         
        int k = 0 , t = p;
        while(true){
            if(t){
                t--;
                st[k]++;
            }
            else{
                t += st[k];
                st[k] = 0;
            }
            k++;
            if(k == n) k = 0;
             
            for(int i = 0 ; i < n ; i++){
                if(st[i]==p){
                    cout << i << endl;
                    flg = true;
                    break;
                }
            }
            if(flg) break;
        }
    }
    return 0;
}
