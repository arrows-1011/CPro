#include <iostream>
#include <string>

using namespace std;
 
int judge(char c){
    char right[12]={'y','h','n','u','j','m','i','k','o','l','p'};
     
    for(int i = 0 ; i < 11 ; i++){
        if(c == right[i]) return 1;
    }
    return 0;
}
 
int main(void){
    string str;
     
    while(1){
        int cnt = 0;
        cin >> str;
        if(str == "#") break;
 
        for(int i = 1 ; i < str.size() ; i++){
            if(judge(str[i-1]) != judge(str[i])) cnt++;
        }    
        cout << cnt << endl;
    }   
    return 0;
}
