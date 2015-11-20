#include <iostream>

using namespace std;
 
int judge(int);
 
int main(){
    int n,age;
 
    for(;;){
	cin >> n;
	if(n == 0) break;
	
	int cnt[7] = {0};
	for(int i = 0 ; i < n ; i++){
	    cin >> age;
	    cnt[judge(age)]++;
	}
	for(int i = 0 ; i < 7 ; i++){
	    cout << cnt[i] << endl;
	}
    }
    return 0;
}
 
int judge(int age){
    return min(age/10,6);
}
