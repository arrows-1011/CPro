#include <iostream>
#include <algorithm>

using namespace std;
 
int cnt_500(double f){
    if(f < 35.5) return 1;
    else if(f < 37.5) return 2;
    else if(f < 40) return 3;
    else if(f < 43) return 4;
    else if(f < 50) return 5;
    else if(f < 55) return 6;
    else if(f < 70) return 7; 
    return 8;
}
 
int cnt_1000(double t){
    if(t < 71) return 1;
    else if(t < 77) return 2;
    else if(t < 83) return 3;
    else if(t < 89) return 4;
    else if(t < 105) return 5;
    else if(t < 116) return 6;
    else if(t < 148) return 7;  
    return 8;
}
 
int main(){
    double f,t;
    while(cin >> f >> t){
        int grade = max(cnt_500(f),cnt_1000(t));
        switch(grade){
	case 1:
	    cout << "AAA" << endl;
	    break;
	case 2:
	    cout << "AA" << endl;
	    break;
	case 3:
	    cout << 'A' << endl;
	    break;
	case 4:
	    cout << 'B' << endl;
	    break;
	case 5:
	    cout << 'C' << endl;
	    break;
	case 6:
	    cout << 'D' << endl;
	    break;
	case 7:
	    cout << 'E' << endl;
	    break;
	case 8:
	    cout << "NA" << endl;
	    break;
        } 
    }
    return 0;
}
