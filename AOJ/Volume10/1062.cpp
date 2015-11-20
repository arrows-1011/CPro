#include <iostream>
#include <cstdio>

using namespace std;
 
int main(){
    int n;
     
    while(cin >> n,n){
        int h,m,dm,lcnt=0,dcnt=0,mcnt = 0,ll=0,dd=0,mm=0;
        for(int i = 0 ; i < n ; i++){
            scanf("%d:%d %d" ,&h ,&m ,&dm);
            if((2 <= h && h < 11) || (15 <= h && h < 18)) continue;
            if(h < 2) h += 24;
            int t = h*60+m,dt = h*60+dm;
            if(dt < t) dt += 60;
            int a = dt-t;
         
            if(11 <= h && h <= 14){
                lcnt++;
                if(a <= 8) ll++;
            }
            else if(18 <= h && h <= 20){
                dcnt++;
                if(a <= 8) dd++;
            }
            else if(21 <= h && h <= 25){
                mcnt++;
                if(a <= 8) mm++;
            }
        }
        if(!lcnt) cout << "lunch no guest" << endl;
        else cout << "lunch " << ll*100/lcnt << endl;
        if(!dcnt) cout << "dinner no guest" << endl;
        else cout << "dinner " << dd*100/dcnt << endl;
        if(!mcnt) cout << "midnight no guest" << endl;
        else cout << "midnight " << mm*100/mcnt << endl;
    } 
    return 0;             
}
