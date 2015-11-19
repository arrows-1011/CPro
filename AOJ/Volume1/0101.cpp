#include <iostream>
#include <string>

using namespace std;

#define rep(k,n) for(int k = 0 ; k < 7 ; k++)
 
int main(){
    string str;
    int n;
     
    cin >> n;
    getline(cin,str);
    while(n--){
        getline(cin,str);
        for(int j = 0 ; j < (int)str.length() ; j++){
            string key = str.substr(j,7),repl;
            if(key == "Hoshino"){
                repl = "Hoshina";
                rep(k,n) str[j+k] = repl[k];
            }
        }
        cout << str << endl;
    }
    return 0;
}
