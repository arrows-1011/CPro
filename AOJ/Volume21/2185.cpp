#include <iostream>

using namespace std;
 
int main(){
    int d,X,Y,W,H,n,x,y;
 
    cin >> d;
    while(d--){
        int cnt = 0;
         
        cin >> X >> Y >> W >> H;
        cin >> n;
        while(n--){
            cin >> x >> y;
             
            if((X <= x && x <= X+W)&&(Y <= y && y <= Y+H)) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
