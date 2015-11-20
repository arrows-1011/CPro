#include <iostream>

using namespace std;
 
int main(){
    int n;
    while(cin >> n,n){
        int ans = 0;
        while(n) ans += n/=5;
        cout << ans << endl;
    }
    return 0;
}
