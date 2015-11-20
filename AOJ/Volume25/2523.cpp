#include <iostream>
#include <string>

using namespace std;

#define LIMIT 1000000000
 
bool check(long long key){
    if(key > LIMIT) return true;
    return false;
}
 
int main(){
    long long n,T,ans,total = 0;
    string str;
    bool flg = false;
 
    cin >> n >> T >> str;
    for(int i = 0 ; i < str.size() ; i++){
        if('0' <= str[i] && str[i] <= '9'){
            if(str[i] == '0') total++;
            else{
                ans = 1;
                for(int j = 0 ; j < str[i]-'0' ; j++){
                    ans *= n;
                    if(check(ans)){
                        flg = true;
                        goto end;
                    }
                }
                total += ans;
            }
        }
    }
    total *= T;
    if(total > LIMIT) flg = true;
     
end:
    if(flg) cout << "TLE" << endl;
    else cout << total << endl;
     
    return 0;
}
