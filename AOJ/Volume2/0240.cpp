#include <iostream>
#include <cmath>

using namespace std;
 
int main(){
    int n,b,t,y,r;
     
    for(;;){
        cin >> n;
        if(n == 0) break;
        cin >> y;
        int mn = 0;
        double max = 0;
        while(n--){
            double g = 0;
            cin >> b >> r >> t;
             
            if(t == 1){
                g = 1 + (double)y*r/100;
            }
            else{
                g = pow(1+(double)r/100,y);
            }
            if(max < g){
                max = g;
                mn = b;
            }
        }
        cout << mn << endl;
    } 
    return 0;
}
