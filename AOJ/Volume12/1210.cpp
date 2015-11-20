#include <iostream>

using namespace std;
 
int main(){
    int n;
 
    while(cin >> n ,n){
	string str;
	int d[] = {1,2,3,4,5,6};
 
	for(int i = 0 ; i < n ; i++){
	    cin >> str;
 
	    int tmp = d[0];
	    if(str == "north"){
		d[0] = d[4];
		d[4] = d[5];
		d[5] = d[1];
		d[1] = tmp;
	    }
	    else if(str == "east"){
		d[0] = d[2];
		d[2] = d[5];
		d[5] = d[3];
		d[3] = tmp;
	    }
	    else if(str == "west"){
		d[0] = d[3];
		d[3] = d[5];
		d[5] = d[2];
		d[2] = tmp;
	    }
	    else{
		d[0] = d[1];
		d[1] = d[5];
		d[5] = d[4];
		d[4] = tmp;
	    }
	}
	cout << d[0] << endl;
    }
    return 0;
}
