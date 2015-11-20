#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main(){
    int n,m;
    int check;
 
    cin >> n >> m;
    check = n;
 
    while(m--){
	cin >> n;
	check = __gcd(n,check);
    }
 
    cout << (check == 1 ? "Yes" : "No") << endl;
    return 0;
}
