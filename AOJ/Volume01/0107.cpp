#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define PI 3.1415926535
 
int main(){
    double a,b,c,d;
    int n;
     
    while(1){
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;

        double e = min(min(sqrt(pow(a,2)+pow(b,2)),
			   sqrt(pow(a,2)+pow(c,2))),sqrt(pow(b,2)+pow(c,2)));
         
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> d;
            if(d*2 <= e) cout << "NA" << endl;
            else cout << "OK" << endl;
        }
    }     
    return 0;
}
