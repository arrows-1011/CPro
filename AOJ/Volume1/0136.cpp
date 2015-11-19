#include <iostream>
 
using namespace std;
 
int main(){
    int n;
    int cnt[6] = {0};
    double a;
 
    cin >> n;
    while(n--){
	cin >> a;
	if(a < 165) cnt[0]++;
	else if(a < 170) cnt[1]++;
	else if(a < 175) cnt[2]++;
	else if(a < 180) cnt[3]++;
	else if(a < 185) cnt[4]++;
	else cnt[5]++;
    }
 
    for(int i = 0 ; i < 6 ; i++){
	cout << i+1 << ":";
	for(int j = 0 ; j < cnt[i] ; j++){
	    cout << "*";
	}
	cout << endl;
    }
    return 0;
}
