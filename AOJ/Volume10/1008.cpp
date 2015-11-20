#include <iostream>

using namespace std;

const int MAX = 1000001;
  
int main(){
    int n,s;
  
    while(cin >> n ,n){
	int m[MAX]={0};
	int ans = 0,num = 0;
	for(int i = 0 ; i < n ; i++){
	    cin >> s;
	    m[s]++;
  
	    if(ans < m[s]){
		ans = m[s];
		num = s;
	    }
	}
	if(ans > n / 2) cout << num << endl;
	else cout << "NO COLOR" << endl;
    }
    return 0;
}
