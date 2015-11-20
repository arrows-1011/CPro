#include <iostream>
 
using namespace std;
 
int main(){
    int L,A,B,C,D,count = 0;
 
    cin >> L >> A >> B >> C >> D;
    for(; ;){
	if( A <= 0 && B <= 0)  break;
	A -= C;
	B -= D;
	count++;
    }
    cout << L - count << endl;
    return 0;
 
}
