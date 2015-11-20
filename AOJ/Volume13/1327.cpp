#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;
 
int N,M,T;
 
mat mul(mat &A,mat &B){
    mat C(A.size(),vec(B[0].size()));
    for(int i = 0 ; i < (int)A.size() ; i++){
	for(int k = 0 ; k < (int)B.size() ; k++){
	    for(int j = 0 ; j < (int)B[0].size() ; j++){
		C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % M;
	    }
	}
    }
    return C;
}
 
mat pow(mat A,ll n){
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
    int a[3];
    while(cin >> N >> M >> a[0] >> a[1] >> a[2] >> T, N){
	mat S(N,vec(1));
	for(int i = 0 ; i < N ; i++){
	    cin >> S[i][0];
	}
	mat A(N,vec(N));
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < N ; j++){
		A[i][j] = 0;
	    }
	    for(int j = i-1, k = 0 ; j < i+2 ; j++, k++){
		if(j < 0 || j >= N) continue;
		A[i][j] = a[k];
	    }
	}
	mat B = pow(A,T);
	mat C = mul(B,S);
	for(int i = 0 ; i < N ; i++){
	    if(i > 0) cout << " ";
	    cout << C[i][0];
	}
	cout << endl;
    }
    return 0;
}
