#include <iostream>

using namespace std;
 
int main(){
    int n,ball,fb;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x[11] = {0},y[11] = {0};
        int flg = 0;
        cin >> fb;
        x[0] = fb;
        for(int j = 1 ; j < 10 ; j++){
            cin >> ball;
            if(x[j-1] < ball){
                x[j] = ball;
                y[j] = y[j-1];
            }
            else if(y[j-1] < ball){
                y[j] = ball;
                x[j] = x[j-1];
            }
            else flg = 1;
        }
	cout << (flg == 0 ? "YES" : "NO") << endl;
    }
    return 0;
}
