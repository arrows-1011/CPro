#include <iostream>
 
using namespace std;
  
int main(){
    float a,b,c,d,e,f,g,h;
    int t;
   
    cin >> t;
    while(t--){
	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	if((d-b)/(c-a) == (h-f)/(g-e)){
	    cout << "YES" << endl;
	}else{
	    cout << "NO" << endl;
	}
    }
    return 0;
}
