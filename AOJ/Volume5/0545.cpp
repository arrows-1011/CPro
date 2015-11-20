#include <iostream>

using namespace std;

#define MAX 502
#define MAX_P 10002
 
int main(){
    int n,m;
     
    while(cin >> n >> m ,n+m){
        int a,b,tmp[MAX]={0},cnt=0,friA[MAX_P]={0},friB[MAX_P]={0},t=0;
        for(int i = 0 ; i < m ; i++){
            cin >> a >> b;
            if(a == 1){
                tmp[b] = 1;
            }
            else{
                friA[t] = a;
                friB[t] = b;
                t++;
	    }
        }
         
        for(int i = 0 ; i < t ; i++){
            if(tmp[friA[i]]==1&&!tmp[friB[i]]) tmp[friB[i]] = 2;
            else if(!tmp[friA[i]]&&tmp[friB[i]]==1) tmp[friA[i]] = 2;
        }
         
        for(int i = 0 ; i < MAX ; i++){
            if(tmp[i] > 0){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
