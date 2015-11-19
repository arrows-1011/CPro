#include <iostream>
#include <string>

using namespace std;
 
int main(){
    string str;
    while(getline(cin,str)){
        int flg = 0;
        while(true){
            for(int i = 0 ; i < str.length() ; i++){
                string key1 = str.substr(i,3),key2 = str.substr(i,4);
                if(key1 == "the" || key2 == "that" || key2 == "this") flg = 1;
            }
            if(flg) break;
            else{
                for(int j = 0 ; j < str.length() ; j++){
                    if('a' <= str[j] && str[j] <= 'z'){
                        str[j] -= 'a' - 'A';
                        str[j] = (char)('A'+(str[j]-'A'+26+1)%26);
                        str[j] += 'a' - 'A';
                    }
                }
            }
        }
        cout << str << endl;
    } 
    return 0;
}
