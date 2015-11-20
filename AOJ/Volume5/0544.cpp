#include <iostream>

using namespace std;

#define MAX 1000
 
int main(){
    int n,m;
    int ms[MAX+1];
     
    while(true){
        cin >> n >> m;
        if(!n&&!m) break;
         
        for(int i = 0 ; i < n ; i++) cin >> ms[i];
     
        int go,t=0,cnt = 0;
        bool flg = false;
         
        for(int i = 0 ; i < m ; i++){
            cin >> go;
            if(!flg){
                t += go;
                t += ms[t];
                cnt++;
                if(t >= n-1) flg = true;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
