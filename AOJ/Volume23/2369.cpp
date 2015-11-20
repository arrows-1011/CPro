#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 514
 
string S;
int memo[MAX][MAX];
 
bool rec(int L,int R){
    int &res = memo[L][R];
    if(res != -1) return res;
    if(L > R) return 1;
    if(S[L] != 'm' || S[R] != 'w') return (res = 0);
    res = 0;
    for(int i = L+1 ; i < R ; i++){
        if(S[i] == 'e'){
            res = max(res,rec(L+1,i-1)&rec(i+1,R-1));
        }
    }
    return res;
}
 
int main(){
    cin >> S;
    memset(memo,-1,sizeof(memo));
    cout << (rec(0,S.size()-1) ? "Cat" : "Rabbit") << endl;
    return 0;
}
