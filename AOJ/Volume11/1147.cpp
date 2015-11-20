#include <iostream>

using namespace std;
 
int main(){
    int n;
    int s[1000];
    int max,min,sum,ave;
 
    while(1){
	max = sum = ave = 0;
	min = 1000;
 
	cin >> n;
	if(n == 0) break;
	for(int i = 0 ; i < n ; i++){
	    cin >> s[i];
	}
	for(int i = 0 ; i < n ; i++){
	    if( max < s[i] ) max = s[i];
	    if( min > s[i] ) min = s[i];
	    sum += s[i];
	}
	sum = sum - max - min;
	ave = sum / (n-2);
	cout << ave << endl;
    }
    return 0;
 
}
