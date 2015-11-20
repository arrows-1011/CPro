#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 300001
typedef unsigned long long ull;
const ull B = 1000000007ULL;
 
int main(){
    int N,M;
    char s[MAX];
    scanf("%d%d%s",&N,&M,s);
    vector<ull> p(N+1),hash(N+1);
    p[0] = 1; hash[0] = 0;
    for(int i = 0 ; i < N ; i++){
        hash[i+1] = hash[i]*B + s[i];
        p[i+1] = p[i]*B;
    }
    int L = 0, R = 0;
    set<ull> st;
    while(M--){
        scanf("%s",s);
        if(s[0] == 'L' && s[1] == '+'){
            L++;
        }else if(s[0] == 'L' && s[1] == '-'){
            L--;
        }else if(s[0] == 'R' && s[1] == '+'){
            R++;
        }else{
            R--;
        }
        st.insert(hash[R+1]-hash[L]*p[R-L+1]);
    }
    printf("%d\n",(int)st.size());
    return 0;
}
