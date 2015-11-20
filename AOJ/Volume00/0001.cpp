#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main(){
    int M[10];
    for(int i = 0; i < 10; i++){
	cin >> M[i];
    }
    sort(M, M+10, greater<int>());
    for(int i = 0 ; i < 3 ; i++){
	cout << M[i] << endl;
    }
    return 0;
}
