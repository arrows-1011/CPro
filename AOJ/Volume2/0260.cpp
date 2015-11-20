#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
typedef unsigned int ui;
 
int main(){
    int n,P,in;
 
    while(cin >> n ,n){
	vector<int> J;
	ui sum = 0;
 
	for(int i = 0 ; i < n ; i++){
	    cin >> P;
	    sum += P;
	}
 
	for(int i = 0 ; i < n-1 ; i++){
	    cin >> in;
	    sum += in;
	    J.push_back(in);
	}
 
	ui ans = 0;
	sort(J.begin(),J.end());
 
	for(int i = 0,j = 1 ; i < n-1 ; i++,j++){
	    ans = max(ans,sum*j);
	    sum -= J[i];
	}
 
	cout << max(ans,sum*n) << endl;
    }
    return 0;
}
