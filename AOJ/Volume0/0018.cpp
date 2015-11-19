#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    int num[5];
 
    for(int i = 0 ; i < 5 ; i++){
	cin >> num[i];
    }
    sort(num ,num+5);
    for(int i = 4 ; i >= 0 ; i--){
	if(i == 4) cout << num[i];
	else cout << " " << num[i];
    }
    cout << endl;
    return 0;
}
