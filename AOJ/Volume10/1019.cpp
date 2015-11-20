#include <iostream>

using namespace std;
 
int main(){
    int N,K,S[100000],B[1000][1000];
    int sum;
    int cnt;
 
    while(1){
	cnt = 0;
	cin >> N >> K;
	if( N == 0 && K == 0 ) break;
	for( int i = 0 ; i < K ; i++ ){
	    cin >> S[i];
	}
 
	for( int j = 0 ; j < N ; j++ ){
	    for( int i = 0 ; i < K ; i++ ){
		cin >> B[j][i];
	    }
	}
 
	for( int i = 0 ; i < K ; i++ ){
	    sum = 0;
	    for( int j = 0 ; j < N ; j++ ){
		sum += B[j][i]; 
	    }
	    if( sum <= S[i] ) cnt++;
	}
	if( cnt == K ) cout << "Yes" << endl;
	else cout << "No" << endl;
 
    }
    return 0;
 
}
