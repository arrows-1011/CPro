#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    int n;
    
    while(cin >> n,n){
        int cnt = 0;
        if(n == 6174){
            cout << cnt << endl;
            continue;
        }
        while(true){
            cnt++;
            int d[4],m=10,NA=0;
            for(int i = 0 ; i < 4 ; i++){
                d[i] = n % m;
                n /= 10;
                if(i&&d[i]==d[i-1]) NA++;
            }
            if(NA == 3){
                cout << "NA" << endl;
                break;
            }
            sort(d,d+4);
            int L=d[3]*1000+d[2]*100+d[1]*10+d[0];
            int S=d[0]*1000+d[1]*100+d[2]*10+d[3];
            if(L-S==6174){
                cout << cnt << endl;
                break;
            }
            else n = L-S;
        }
    }
    return 0;
}
