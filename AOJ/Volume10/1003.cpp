#include <iostream>
#include <string>
using namespace std;
 
string str[]={" ","',.!?","abcABC","defDEF","ghiGHI","jklJKL","mnoMNO","pqrsPQRS","tuvTUV","wxyzWXYZ"};
 
int main(){
    string s;
     
    while(cin >> s){
        int len = s.size();
         
        int k = 0;
        if(s[len-1]!='0'){
            s += '0';
            k = 1;
        }
         
        string ans = "";
        for(int i = 0 ; i < len+k ; i++){
            int cnt = 1, j;
            for(j = i+1 ; j < len+k ; j++){
                if(s[i] != s[j]) break;
            }
            if(s[i] == '0'){
                if(j==i+2) ans += " ";
                else if(j==i+3) ans += "  ";
            }
            else{
                ans += str[s[i]-'0'][j-i-1];
            }
            i += j-i-1;
        }
        cout << ans << endl;
    }
     
    return 0;
}
