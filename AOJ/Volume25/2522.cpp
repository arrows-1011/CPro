#include <iostream>
#include <string>

using namespace std;
 
int main(){
    string str;
    bool size = false , num = false , l = false , s = false;
     
    cin >> str;
     
    if(str.size() >= 6) size = true;
    for(int i = 0 ; i < str.size() ; i++){
        if('0' <= str[i] && str[i] <= '9') num = true;
        if('A' <= str[i] && str[i] <= 'Z') l = true;
        if('a' <= str[i] && str[i] <= 'z') s = true;
    }
 
    if(size && num && l && s) cout << "VALID" << endl;
    else cout << "INVALID" << endl;
     
    return 0;
}
