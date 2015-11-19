#include <iostream>
using namespace std;
 
int main(){
    int d;
    while(cin >> d){
	int ans = 0;
	for(int i = d ; i <= 600-d ; i += d){
	    ans += d*(i*i);
	}
	cout << ans << endl;
    }
    return 0;
}
