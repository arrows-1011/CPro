#include <iostream>
#include <cmath>

using namespace std;
 
int main(){
    int n,num,h,w;
     
    while(1){
        double best = 22,tmp;
        int bn;
         
        cin >> n;
        if(!n) break;
         
        for(int i = 0 ; i < n ; i++){
            cin >> num >> h >> w;
             
            double nh = (double)h / 100;
            double BMI = (double)w / (nh*nh);
            if(!i){
                tmp = fabs(BMI-best);
                bn = num;
                continue;
            }
             
            if(tmp > fabs(BMI-best)){
                tmp = fabs(BMI-best);
                bn = num;
            }
        }
        cout << bn << endl;
    }
    return 0;
}
