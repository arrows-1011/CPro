#include <bits/stdc++.h>
 
using namespace std;
 
char p[3][3][4];
char pz[9][4];
 
bool check(char a,char b){
    return (a-32 == b || b-32 == a);
}
 
int rec(int now,int S){
    if(now == 9) return 1;
    int res = 0;
    int X = now%3, Y = now/3;
    for(int s = 0 ; s < 9 ; s++){
        if(S >> s & 1) continue;
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j < 4 ; j++){
                p[Y][X][j] = pz[s][(i+j)%4];
            }
            bool can = true;    
            if(X > 0 && !check(p[Y][X][0],p[Y][X-1][2])){
                can = false;
            }
            if(Y > 0 && !check(p[Y][X][1],p[Y-1][X][3])){
                can = false;            
            }
            if(can) res += rec(now+1,S|(1<<s));
        }
    }
    return res;
}
 
int main(){
    int Tc;
    cin >> Tc;
    while(Tc--){
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 4 ; j++){
                cin >> pz[i][j];
            }
        }
        cout << rec(0,0) << endl;
    }
    return 0;
}
