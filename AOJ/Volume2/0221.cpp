#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
 
string its(int n){
    stringstream s;
    s << n;
    return s.str();
}
 
int main(){
    int n,m;
     
    while(cin >> n >> m ,n+m){
        vector<int> v;
        for(int i = 0 ; i < n ; i++) v.push_back(i+1);
     
        int cnt = 1,t = 0;
        string str;
         
        while(m--){
            bool check = false;
             
            cin >> str;
            if(cnt%15==0){
                if(str != "FizzBuzz"){
                    check = true;
                }
            }
            else if(cnt%3==0){
                if(str != "Fizz"){
                    check = true;
                }
            }
            else if(cnt%5==0){
                if(str != "Buzz"){
                    check = true;
                }
            }
            else{
                if(str!=its(cnt)){
                    check = true;
                }
            }
             
            if(check&&v.size() > 1){
                v.erase(v.begin()+t);
                t %= v.size();
            }
            else t = (t+1)%v.size();
                 
            cnt++;
        }
        for(int i = 0 ; i < v.size() ; i++){
            if(!i) cout << v[i];
            else cout << ' ' << v[i];
        }
        cout << endl;
    }
    return 0;
}
