#include <iostream>
#include <string>

using namespace std;
 
int main(){
    int w[10];
    string str;
 
    while(cin >> str){
	int num = 10;
	for(int i = 0 ; i < num ; i++) w[i] = str[i] - '0';
 
	int a[10] = {0};
	while(num > 1){
	    for(int i = 1 ; i < num ; i++){
		a[i-1] = (w[i-1] + w[i]) % 10;
	    }  
	    for(int i = 0 ; i < num ; i++) w[i] = a[i];
	    num--;
	}
	cout << a[0] << endl;
    }
    return 0;
}
