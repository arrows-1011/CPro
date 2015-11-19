#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    const int w[10] = {1,2,4,8,16,32,64,128,256,512};
    int n;
     
    while(cin >> n){
        int nw[10] = {0};
        int cnt = 0;
        for(int i = 0 ; w[i] <= n ; i++){
            nw[i] = w[i];
            cnt++;
        }
        int sum = 0;
        int nnw[10] = {0};
        int k = 0;
        int m = n;
        for(int i = 0 ; i < cnt ; i++){
            for(int j = cnt-1 ; j >= 0 ; j--){
                 
                if(sum == n) break;
                 
                if(nw[j] <= m){
                    nnw[k++] = nw[j];
                    sum += nw[j];
                    m -= nw[j];
                }
            }
            if(sum == n) break;
        }
        sort(nnw,nnw+k);
         
        for(int i = 0 ; i < k ; i++){
            if(i == 0) cout << nnw[i];
            else cout << ' ' << nnw[i];
        }
        cout << endl;
    }
 
    return 0;
}
