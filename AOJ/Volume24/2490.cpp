#include <iostream>
#include <string>

using namespace std;
 
int main(){
    int n,num,flg = 0;
    char ch;
    long long check = 0;
     
    cin >> n;
    while(n--){
        cin >> ch >> num;
        if(ch == '(') check += num;
        else check -= num;
         
        if(check < 0){
            flg = 1;
        }
    }
    if(check) flg = 1;
     
    if(flg) cout << "NO" << endl;
    else cout << "YES" << endl;
     
    return 0;
}
