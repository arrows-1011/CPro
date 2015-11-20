#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 101
 
int main(){
    int n,q;
     
    while(cin >> n >> q ,n+q){
        int flg = 0 , cnt[MAX] , max_n = 0 , m , d;
        fill(cnt,cnt+MAX,0);
        for(int i = 0 ; i < n ; i++){
            cin >> m;
            for(int j = 0 ; j < m ; j++){
                cin >> d;
                ++cnt[d];
                max_n = max(max_n,cnt[d]);
            }
        }
         
        if(max_n >= q) flg = 1;
         
        if(flg){
            int res;
            for(int k = 1 ;; k++){
                if(cnt[k] >= q && cnt[k] == max_n){
                    res = k;
                    break;
                }
            }
            cout << res << endl;
        }
        else cout << flg << endl;
    }
    return 0;
}
