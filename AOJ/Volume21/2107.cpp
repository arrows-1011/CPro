#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int,int> pii;
 
mat mul(mat &A,mat &B){
    mat C(A.size(),vec(B[0].size()));
    for(int i = 0 ; i < (int)A.size() ; i++){
        for(int k = 0 ; k < (int)B.size() ; k++){
            for(int j = 0 ; j < (int)B[0].size() ; j++){
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]);
            }
        }
    }
    return C;
}
 
mat pow(mat A,int n){
    mat B(A.size(),vec(A.size()));
    for(int i = 0 ; i < (int)A.size() ; i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if(n & 1) B = mul(B,A);
        A = mul(A,A);
        n >>= 1;
    }
    return B;
}
 
int main(){
    int N,M,Z,s,t;
    while(cin >> N >> M >> Z, N){
        vector<pii> v;
        v.push_back(pii(0,0));
        for(int i = 0 ; i < M ; i++){
            cin >> s >> t;
            s--; t--;
            v.push_back(pii(s,t));
            v.push_back(pii(t,s));
        }
        int size = 2*M+1;
        mat A(size,vec(size,0));
        for(int i = 0 ; i < size ; i++){
            int n1 = v[i].second,p1 = v[i].first;
            for(int j = 0 ; j < size ; j++){
                if(i == j || j == 0) continue;
                int n2 = v[j].second,p2 = v[j].first;
                if(n2 == p1) continue;
                if(n1 == p2) A[i][j] = 1;
            }
        }
        bool ok = false;
        mat res = pow(A,Z);
        for(int i = 0 ; i < size ; i++){
            int now = v[i].second;
            ok |= (now == N-1 && res[0][i] != 0);
 
        }
        cout << (ok ? "yes" : "no") << endl;
    }
    return 0;
}
