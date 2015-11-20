#include <iostream>

using namespace std;
 
int main(){ 
    int n,m;
    int quiz[20][20];
    int cnt;
    int max = 0;
 
    cin >> n >> m;
    for( int i = 0 ; i < n ; i++ ){
	cnt = 0;
	for( int j = 0 ; j < m ; j++ ){
	    cin >> quiz[i][j];
	    if( quiz[i][j] == 1 ) cnt++;
	}
	if( max < cnt ) max = cnt;
    }
    cout << max << endl;
    return 0;
}
