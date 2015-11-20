#include <iostream>
#include <string>

using namespace std;
 
int main(){
    string str;
     
    while(getline(cin,str)){
        int JOI = 0 , IOI = 0;
        for(int i = 0 ; i < str.length() ; i++){
            string key = str.substr(i,3),repl;
            if(key == "JOI") JOI++;
            else if(key == "IOI") IOI++;
        }
        cout << JOI << endl;
        cout << IOI << endl;
    }
    return 0;
}
