#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-9
#define M 256
#define INF 1e9
 
int main(){
    int N;
    while(cin >> N, N > 0){
	int I[N+1],R[N+1],O[N+1];
	for(int i = 0 ; i < N ; i++){
	    cin >> I[i];
	}
	int S,A,C;
	double ans = INF;
	for(int s = 0 ; s <= 15 ; s++){
	    for(int a = 0 ; a <= 15 ; a++){
		for(int c = 0 ; c <= 15 ; c++){
		    int x[M] = {0};
		    R[0] = s;
		    for(int i = 1 ; i <= N ;i++){
			R[i] = (a*R[i-1]+c) % M;
			O[i] = (I[i-1]+R[i]) % M;
			x[O[i]]++;
		    }
		    double H = 0;
		    for(int i = 0 ; i < M ; i++){
			double p = (double)x[i]/N;
			if(p > 0){
			    H -= p*log(p);
			}
		    }
		    if(H+EPS < ans){
			ans = H;
			S = s; A = a; C = c;
		    }
		}
	    }
	}
	cout << S << " " << A << " " << C << endl;
    }
    return 0;
}
