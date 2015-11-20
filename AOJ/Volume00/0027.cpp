#include <iostream>

using namespace std;

int zeller(int Y,int M,int D){
    if(M < 3){
	Y--;
	M += 12;
    }
    return (Y+Y/4-Y/100+Y/400+(13*M+8)/5+D)%7;
}

int main(){
    string s[] = {"Sunday",
		  "Monday",
		  "Tuesday",
		  "Wednesday",
		  "Thursday",
		  "Friday",
		  "Saturday",
		  "Sunday"};
    int M,D;
    while(cin >> M >> D, M){
	cout << s[zeller(2004,M,D)] << endl;
    }
    return 0;
}
