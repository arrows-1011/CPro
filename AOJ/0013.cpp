#include <iostream>
#include <stack>

using namespace std;
 
int main(){
    stack<int> car;
    int n,res[10000],cnt = 0,cnt2 = 0;
 
    while(cin >> n){
 
	if(n != 0){
	    car.push(n);
	}else{
	    res[cnt] = car.top();
	    car.pop();
	    cnt++;
	    cnt2++;
	}
    }
 
    cnt = 0;
    while(cnt2){
	cout << res[cnt] << endl; 
	cnt++;
	cnt2--;
    }
    return 0;
}
