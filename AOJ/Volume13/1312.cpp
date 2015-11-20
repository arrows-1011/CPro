#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1001
#define MAX_T 12
typedef unsigned long long ull;
  
int N,M,P;
char field[MAX][MAX],patterns[MAX_T][MAX][MAX];
char pattern[MAX][MAX],tmp2[MAX][MAX];
 
set<ull> st;
ull hash[MAX][MAX],tmp[MAX][MAX];
  
void compute_hash(char a[MAX][MAX],int n,int m){
    const ull B1 = 9973;
    const ull B2 = 100000007;
    
    ull t1 = 1;
    for(int j = 0 ; j < P ; j++) t1 *= B1;
    
    for(int i = 0 ; i < n ; i++){
        ull e = 0;
        for(int j = 0 ; j < P ; j++) e = e * B1 + a[i][j];
        for(int j = 0 ; j + P <= m ; j++){
            tmp[i][j] = e;
            if(j + P < m) e = e * B1 - t1 * a[i][j] + a[i][j+P]; 
        }
    }
    
    ull t2 = 1;
    for(int i = 0 ; i < P ; i++) t2 *= B2;
    
    for(int j = 0 ; j + P <= m ; j++){
        ull e = 0;
        for(int i = 0 ; i < P ; i++) e = e * B2 + tmp[i][j];
      
        for(int i = 0 ; i + P <= n ; i++){
            hash[i][j] = e;
            if(i + P < n) e = e * B2 - t2 * tmp[i][j] + tmp[i+P][j];
        }
    }
}
  
int solve(int idx){
    int cnt = 0;
    compute_hash(patterns[idx], P, P);
    ull res = hash[0][0];
    if(st.count(res)) return 0;
    st.insert(res);
    compute_hash(field, N, M);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(res == hash[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}
 
int getNum(char ch){
    if(isupper(ch)){
        return (ch - 'A');
    }else if(islower(ch)){
        return (ch - 'a' + 26);
    }else if(isdigit(ch)){
        return (ch - '0' + 52);
    }
    return (ch == '+' ? 62 : 63);
}
 
string getBi(int x){
    string res;
    while(x > 0){
        res += (char)((x % 2) + '0');
        x /= 2;
    }
    while(res.size() != 6){
        res += '0';
    }
    reverse(res.begin(),res.end());
    return res;
}
 
void rotate(char a[MAX][MAX],char b[MAX][MAX]){
    for(int i = 0 ; i < P ; i++){
        for(int j = 0 ; j < P ; j++){
            a[i][j] = b[P-j-1][i];
        }
    }
}
 
void copy(char a[MAX][MAX],char b[MAX][MAX]){
    for(int i = 0 ; i < P ; i++){
        for(int j = 0 ; j < P ; j++){
            a[i][j] = b[i][j];
        }
    }
}
 
void mirror(char a[MAX][MAX], int k){
    copy(tmp2, a);
    if(k == 0){
        for(int i = 0 ; i < P ; i++){
            for(int j = 0 ; j < P ; j++){
                a[i][j] = tmp2[i][P-j-1];
            }
        }
    }else if(k == 1){
        for(int i = 0 ; i < P ; i++){
            for(int j = 0 ; j < P ; j++){
                a[P-i-1][j] = tmp2[i][j];
            }
        }
    }
}
 
void init(){
    st.clear();
}
 
int main(){
    while(cin >> M >> N >> P, M){
        init();
        string in;
        for(int i = 0 ; i < N ; i++){
            cin >> in;
            for(int j = 0 ; j < (M+5)/6 ; j++){
                string str = getBi(getNum(in[j]));
                for(int k = 0 ; k < 6 ; k++){
                    field[i][j*6+k] = str[k];
                }
            }
        }
        for(int i = 0 ; i < P ; i++){
            cin >> in;
            for(int j = 0 ; j < (P+5)/6 ; j++){
                string str = getBi(getNum(in[j]));
                for(int k = 0 ; k < P-j*6 ; k++){
                    pattern[i][j*6+k] = str[k];
                }
            }
        }
        int res = 0;
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                copy(tmp2, pattern);
                copy(patterns[j*4], pattern);
                for(int k = 0 ; k < 3 ; k++){
                    rotate(patterns[j*4+k+1], patterns[j*4+k]);
                }
                copy(pattern, tmp2);
                mirror(pattern, j);
            }
            rotate(pattern, patterns[0]);
            for(int j = 0 ; j < 12 ; j++){
                res += solve(j);
            }
        }
        if(P > N || P > M){
            cout << 0 << endl;
            continue;
        }
        cout << res << endl;
    }
    return 0;
}
