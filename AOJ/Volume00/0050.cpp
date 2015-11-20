#include <iostream>
#include <string>

using namespace std;

#define rep(j,n) for(int j = 0 ; j < 5 ; j++)
 
int main(){
    string str; 
    while(getline(cin,str)){
        for(int i = 0 ; i < str.length() ; i++){
            string key = str.substr(i,5),repl;
            if(key == "apple"){
                repl = "peach";
                rep(j,n) str[i+j] = repl[j];
            }
            else if(key == "peach"){
                repl = "apple";
                rep(j,n) str[i+j] = repl[j];
            }
        }
        cout << str << endl;
    }
    return 0;
}
