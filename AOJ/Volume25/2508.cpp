#include <iostream>
#include <string>

using namespace std;

#define MAX 101
 
string mj;
 
void set(){
    for(int i = 0 ; i < 26 ; i++) mj += 'a'+i;
    for(char i = 26 ; i < 52 ; i++) mj += 'A'+i-26;
}
 
char change(int t,char ch){
    int i;
    for(i = 0 ; i < 52 ; i++){
        if(mj[i] == ch) break;
    }
    i -= t;
    if(i < 0) i+= 52;
     
    return mj[i];
}
 
 
int main(){
    int n,a[MAX];
     
    set();
    while(cin >> n,n){
        for(int i = 0 ; i < n ; i++) cin >> a[i];
        string str ,tmp = "";
        int k = 0;
        cin >> str;
        for(int i = 0 ; i < str.size() ; i++){
            tmp += change(a[k++],str[i]);
            if(k >= n) k = 0;
        }
        cout << tmp << endl;
    }
    return 0;
}
