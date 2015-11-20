#include <iostream>

using namespace std;
 
int main(){
    int n,team1,team2,Point[101],po1,po2,cnt;
 
    for( int i = 0 ; i < 101 ; i++ ) Point[i] = 0;
   
    cin >> n;
    for( int i = 0; i < n*(n-1)/2 ; i++ ){
 
	cin >> team1 >> team2 >> po1 >> po2;
	if( po1 > po2 ) Point[team1] += 3;
	else if( po1 < po2 ) Point[team2] += 3;
	else{
	    Point[team1]++; Point[team2]++;
	}
    }
 
    for( int i = 1 ; i <= n ; i++ ){
	cnt = 1;
	for( int j = 1 ; j <= n ; j++ ){
	    if( Point[i] < Point[j] ) cnt++;
	}
	cout << cnt << endl;
    }
    return 0;
}
