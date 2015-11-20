#include <iostream>
#include <string>

using namespace std;
 
int main(){
    string str;
     
    while(1){
        getline(cin,str);
        if(str == "END OF INPUT") break;
         
        int cnt = 0;
        for(int i = 0 ; i < str.size() ; i++){
            cnt++;
            if(str[i] == ' '){
                cout << cnt-1;
                cnt = 0;
            }
            if(str[i] == str[str.size()-1] && i == str.size()-1) cout << cnt << endl;
        }
    }     
    return 0;
}
