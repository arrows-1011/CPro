#include <iostream>

using namespace std;
 
int map[5][5];
 
int all(int ax,int ay,int bx,int by){
    for( int i = ax ; i <= bx ; i++ ){
	for( int j = ay ; j <= by ; j++ ){
	    if(! map[i][j]) return 0; 
	}
    }
    return 1;
}
 
int main(){
    int m;
    int max;
 
    cin >> m;
    for( int o = 0 ; o < m ; o++ ){
	max = 0; 
	for( int i = 0 ; i < 5 ; i++ ){
	    for( int j = 0 ; j < 5 ; j++ ){
		cin >> map[i][j];    
	    }
	}
 
	for( int i = 0 ; i < 5 ; i++ ){
	    for( int j = 0 ; j < 5 ; j++ ){
		for( int k = i ; k < 5 ; k++ ){
		    for( int l = j ; l < 5 ; l++ ){
			if( all( i , j , k , l ) ){
			    if( max < (k-i+1)*(l-j+1) ) max=(k-i+1)*(l-j+1);
			}
		    }
		}
	    }
	}
	cout << max << endl;
    }
    return 0;
}
