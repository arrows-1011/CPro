#include <iostream>
#include <algorithm>

using namespace std;

#define INF 9999999
 
int main(){
    int e;
     
    while(cin >> e,e){
        //x+y^2+z^3=e
        int ans = INF;
         
        for(int z = 0 ; z*z*z <= e ; z++){
            for(int y = 0 ; (y*y)+(z*z*z) <= e ; y++){
                ans = min(ans,e-y*y-z*z*z+y+z);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
