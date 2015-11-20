#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
 
int main(){
    string str;
    cin >> str;
    for(int i = 0 ; i < (int)str.size() ; i++){
        cout << (char)('A'+(str[i]-'A'+26-3)%26);
    }
    puts("");
    return 0;
}
