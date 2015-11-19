#include <iostream>

using namespace std;

#define MAX 26
 
int main(){
    int n,a[MAX];
     
    while(cin >> n,n){
        for(int i = 0 ; i < n ; i++) cin >> a[i];
        int ohajiki = 32,j = 0,d = 0;
        while(1){
            if(ohajiki == 1) break;
            if(j%2==0){
                ohajiki -= (ohajiki-1)%5;
            }
            else{
                ohajiki -= a[d++];
                if(d == n) d = 0;
            }
            j++;
            cout << ohajiki << endl;
        }
        cout << '0' << endl;
    }
    return 0;
}
