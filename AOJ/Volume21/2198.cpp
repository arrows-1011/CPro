#include <iostream>
#include <algorithm>
 
using namespace std;
 
struct Crop{
    double inc;
    string name;
 
    bool operator < (const Crop &c)const{
	if(c.inc != inc){
	    return c.inc < inc;
	}else{
	    return c.name > name;
	}
    }
};
 
int main(){
    int n,P,A,B,C,D,E,F,S,M;
    string L;
 
    while(cin >> n, n){
	Crop data[n];
 
	for(int i = 0 ; i < n ; i++){
	    cin >> L >> P >> A >> B >> C 
		>> D >> E >> F >> S >> M;
 
	    int Time = A + B + C + D + E;
	    Time += (M-1) * (D + E);
	    S = S*M*F;
 
	    data[i].name = L;
	    data[i].inc = (double)(S-P) / Time;
	}
 
	sort(data,data+n);
 
	for(int i = 0 ; i < n ; i++){
	    cout << data[i].name << endl;
	}
	cout << "#" << endl;
    }
    return 0;
}
