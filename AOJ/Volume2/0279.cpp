#include <iostream>

using namespace std;

const int MAX = 1e4;
 
int main(){
    int n,d[MAX+1];
 
    while(cin >> n ,n){
	int num = 0;
	bool flg = false;
 
	for(int i = 0 ; i < n ; i++){
	    cin >> d[i];
	    if(d[i] > 1) flg = true;
	    if(d[i]) ++num;
	}
	if(!flg) cout << "NA" << endl;
	else cout << ++num << endl;
    } 
    return 0;
}
