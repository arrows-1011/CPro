#include <iostream>
using namespace std;
const int MAX = 71;
 
char judge(char c){
    if('0' <= c && c <= '9') return c;
    return '#';
}
 
string strMax(string x,string y){
    string tx = "",ty = "";
    bool flg = false;
     
    if(x == "#" && y == "#") return "#";
    if(x == "#") return y;
    if(y == "#") return x;
     
    for(int i = 0 ; i < x.size() ; i++){
        if(x[i] == '0' && !flg){
            continue;
        }
        else{
            flg = true;
            tx += x[i];
        }
    }
    x = tx;
    flg = false;
    for(int i = 0 ; i < y.size() ; i++){
        if(y[i] == '0' && !flg){
            continue;
        }
        else{
            flg = true;
            ty += y[i];
        }
    }
    y = ty;
     
    if(x.size() > y.size()) return x;
    else if(x.size() < y.size()) return y;
     
    for(int i = 0 ; i < x.size() ; i++){
        if(x[i] > y[i]) return x;
        else if(x[i] < y[i]) return y;
    }
    return x;
}
 
int main(){
    int H,W;
    string str[MAX];
     
    while(cin >> H >> W , H + W){
        string dp[MAX][MAX];
        for(int i = 0 ; i < W ; i++){
            cin >> str[i];
        }
        dp[0][0] = judge(str[0][0]);
         
        for(int i = 1 ; i < W ; i++){
            if(judge(str[i][0]) == '#'){
                dp[i][0] = "#";
            }
            else if(dp[i-1][0] != "#"){
                dp[i][0] = dp[i-1][0];
                dp[i][0] += judge(str[i][0]);
            }
            else{
                dp[i][0] += judge(str[i][0]);
            }
        }
         
        for(int j = 1 ; j < H ; j++){
            if(judge(str[0][j]) == '#'){
                dp[0][j] = "#";
            }
            else if(dp[0][j-1] != "#"){
                dp[0][j] = dp[0][j-1];
                dp[0][j] += judge(str[0][j]);
            }
            else{
                dp[0][j] += judge(str[0][j]);
            }
        }
         
        string ans = "0";
        for(int i = 1 ; i < W ; i++){
            for(int j = 1 ; j < H ; j++){
                if(judge(str[i][j]) == '#') dp[i][j] = '#';
                else{
                    dp[i][j] = strMax(dp[i-1][j],dp[i][j-1]);
                    if(dp[i][j] != "#"){
                        dp[i][j] += judge(str[i][j]);
                    }
                    else{
                        dp[i][j] = "";
                        dp[i][j] += judge(str[i][j]);
                    }
                }
            }
        }
        for(int i = 0 ; i < W ; i++){
            for(int j = 0 ; j < H ; j++){
                ans = strMax(ans,dp[i][j]);
	    }
	}
        cout << ans << endl;
    }
    return 0;
}
