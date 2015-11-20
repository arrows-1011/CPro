#include <iostream>

using namespace std;

#define MAX 10000
 
int main(){
    int n,num;
     
    while(cin >> n,n){
        int array[MAX]={0};
        for(int i = 0 ; i < n ; i++){
            cin >> num;
            array[num] = 1;
        }
         
        int s,g,flg = 0,t = 0 ,cnt = 0;
        for(int i = 1 ; i < MAX ; i++){
            if(array[i]){
                if(!t){
                    s = i;
                    t++;
                }
                g = i;
                cnt++;
            }
            else{
                if(cnt==1){
                    cnt = 0;
                    if(t&&!flg){
                        cout << s;
                        flg++;
                        t = 0;
                    }
                    else if(t&&flg){
                        cout << ' ' << s;
                        t = 0;
                    }
                }
                else{
                    cnt = 0;
                    if(t&&!flg){
                        cout << s << '-' << g;
                        flg++;
                        t = 0;
                    }
                    else if(t&&flg){
                        cout << ' ' << s << '-' << g;
                        t = 0;
                    }
                    else continue;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
