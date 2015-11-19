#include <iostream>

using namespace std;
 
int main(){
    int s1[5],s2[5];
 
    while(true){
	cin >> s1[0] >> s2[0];
	if(!s1[0]&&!s2[0]) break;
 
	int max = s1[0] + s2[0],num = 1;
	for(int i = 1 ; i < 5 ; i++){
	    cin >> s1[i] >> s2[i];
	    if(max < s1[i]+s2[i]){
		max = s1[i] + s2[i];
		num = i + 1;
	    }
	}
	switch(num){
	case 1:
	    cout << 'A'; break;
	case 2:
	    cout << 'B'; break;
	case 3:
	    cout << 'C'; break;
	case 4:
	    cout << 'D'; break;
	case 5: 
	    cout << 'E'; break;
	}
	cout << ' ' << max << endl;
    }
    return 0;
}
