#include <iostream>

using namespace std;
 
int main(){
    long long n, sum = 0;
 
    cin >> n;
    while(n--){
	int a,b;
	char c;
 
	cin >> a >> c >> b;
	if(c == '(') sum += b;
	else sum -= b;
  
	if(sum == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
    }
    return 0;
}
