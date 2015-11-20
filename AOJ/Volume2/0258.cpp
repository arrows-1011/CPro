#include <iostream>
#include <cmath>

using namespace std;

#define MAX 502
 
int main(){
    int n;
    int v[MAX];
     
    while(cin >> n,n){       
        for(int i = 0 ; i <= n ; i++){
            cin >> v[i];
        }
         
        int d;
        for(int i = 0 ; i <= n ; i++){
            int tmp = v[i],nv[MAX],t = 0,cnt = 0;
            v[i] = 0;
            for(int k = 0 ; k <= n ; k++){
                if(!v[k]) continue;
                nv[t++] = v[k];
            }
             
            for(int j = 1 ; j < n ; j++){
                if(j==1){
                    d = nv[j] - nv[j-1];
                }
                if(d == nv[j]-nv[j-1]) cnt++;
            }
            if(cnt == n-1){
                cout << tmp << endl;
                break;
            }
            v[i] = tmp;
        }
    }
    return 0;
}
