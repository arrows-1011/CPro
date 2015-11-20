#include <iostream>

using namespace std;
 
int main(){
    int n,c;
 
    while(cin >> n ,n){
	int total = 0;
	for(int i = 0 ; i < n*(n-1)/2 ; i++){
	    cin >> c;
	    total += c;
	}
	cout << total / (n-1) << endl;
    }
 
    return 0;
}
