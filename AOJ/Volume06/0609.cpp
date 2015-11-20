#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 100
#define MAX_M 100
 
int main(){
    int N,M,A[MAX_M],B;
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
	cin >> A[i]; A[i]--;
    }
    int point[MAX_N] = {0};
    for(int i = 0 ; i < M ; i++){
	int X = 0;
	for(int j = 0 ; j < N ; j++){
	    cin >> B; B--;
	    if(A[i] != B){ X++; }
	    else{ point[j]++; }
	}
	point[A[i]] += X;
    }
    for(int i = 0 ; i < N ; i++){
	cout << point[i] << endl;
    }
    return 0;
}
