#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;
 
string str;
 
string its(int n){
    stringstream s;
    s << n;
    return s.str();
}
 
int judge(int n){
    string ss = its(n);
    int len = ss.size();
     
    for(int i = 0 ; i <= len/2 ; i++){
        if(ss[i] != ss[len-i-1]) return 0;
    }
    return 1;
}
 
int main(){
    int n,a,b;
     
    cin >> n;
    for(int i = n ; ; i++){
        if(judge(i)){
            a = i;
            break;
        }
    }
    for(int i = n ; ; i--){
        if(judge(i)) {
            b = i;
            break;
        }
    }
     
    if(abs(n-a) == abs(n-b)) cout << b << endl;
    else if(abs(n-a) < abs(n-b)) cout << a << endl;
    else cout << b << endl;
     
    return 0;
}
