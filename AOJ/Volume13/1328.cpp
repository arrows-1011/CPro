#include <bits/stdc++.h>
 
using namespace std;
  
#define EPS 1e-3
#define equals(a,b) (abs(a-b) < EPS)
typedef vector<double> vec;
typedef vector<vec> mat;
 
vec gauss_jordan(const mat &A,const vec &b){
    int n = A.size();
    mat B(n,vec(n+1));
    for(int i = 0 ; i < n ; i++){
	for(int j = 0 ; j < n ; j++){
	    B[i][j] = A[i][j];
	}
    }
    for(int i = 0 ; i < n ; i++){
	B[i][n] = b[i];
    }
    for(int i = 0 ; i < n ; i++){
	int pivot = i;
	for(int j = i ; j < n ; j++){
	    if(abs(B[j][i]) > abs(B[pivot][i])){
		pivot = j;
	    }
	}
	swap(B[i],B[pivot]);
	if(abs(B[i][i]) < EPS) return vec();
	for(int j = i+1 ; j <= n ; j++){
	    B[i][j] /= B[i][i];
	}
	for(int j = 0 ; j < n ; j++){
	    if(i != j){
		for(int k = i+1 ; k <= n ; k++){
		    B[j][k] -= B[j][i]*B[i][k];
		}
	    }
	}
    }
    vec x(n);
    for(int i = 0 ; i < n ; i++){
	x[i] = B[i][n];
    }
    return x;
}
 
int main(){
    int d;
    while(cin >> d,d){
	int N = d+3;
	mat A(N,vec(d+1));
	vec b(N);
	for(int i = 0 ; i < N ; i++){
	    cin >> b[i];
	    for(int j = 0 ; j <= d ; j++){
		A[i][j] = pow((double)i,j);
	    }
	}
	for(int i = 0 ; i < N ; i++){
	    int idx = 0;
	    mat A2(N-2,vec(d+1));
	    vec b2(N-2);
	    for(int j = 0 ; idx < N-2 ; j++){
		if(i == j) continue;
		A2[idx] = A[j];
		b2[idx++] = b[j];
	    }
	    vec res = gauss_jordan(A2,b2);
	    if(res.size() > 0){
		int x = (i == N-1 ? N-2 : N-1);
		double sum = 0;
		for(int j = 0 ; j < (int)res.size() ; j++){
		    sum += res[j]*pow((double)x,j);
		}
		if(equals(sum,b[x])){
		    cout << i << endl;
		    break;
		}
	    }
	}
    }
    return 0;
}
