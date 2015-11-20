#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <algorithm>

using namespace std;
 
string its(int n){
    stringstream s;
    s << n;
     
    return s.str();
}
 
int main(){
    string str;
    int n;
     
    cin >> n;
    while(n--){
        int cnt = 0;
        cin >> str;
        int len = str.size();
         
        while(len > 1){
            cnt++;
            int MAX = 0;
            for(int i = 0 ; i < len-1; i++){
                int a = atoi(str.substr(0,i+1).c_str());
                int b = atoi(str.substr(i+1,len-1).c_str());
                MAX = max(MAX,a*b);
            }
            str = "";
            str += its(MAX);
            len = str.size();
        }
        cout << cnt << endl;
    }
    return 0;
}
