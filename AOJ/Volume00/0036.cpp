#include <iostream>

using namespace std;
 
char mp[8][8];
 
void ans(char mp[8][8]){
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(mp[i][j]=='1'){
                if(mp[i][j+1]=='1'&&mp[i+1][j]=='1'&&mp[i+1][j+1]=='1'){
                    cout << 'A' << endl;
                    return;
                }
                else if(mp[i+3][j]=='1'){
                    cout << 'B' << endl;
                    return;
                }
                else if(mp[i][j+3]=='1'){
                    cout << 'C' << endl;
                    return;
                }
                else if(mp[i+2][j-1]=='1'){
                    cout << 'D' << endl;
                    return;
                }
                else if(mp[i+1][j+2]=='1'){
                    cout << 'E' << endl;
                    return;
                }
                else if(mp[i+2][j+1]=='1'){
                    cout << 'F' << endl;
                    return;
                }
                else{
                    cout << 'G' << endl;
                    return;
                }
            }
        }
    }
}
 
int main(){
    while(cin >> mp[0][0]){
        for(int i = 0 ; i < 8 ; i++){
            for(int j = 0 ; j < 8 ; j++){
                if(!i&&!j) continue;
                else cin >> mp[i][j];
            }
        }
        ans(mp);
    }
     
    return 0;
}
