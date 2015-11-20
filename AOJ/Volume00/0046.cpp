#include <iostream>
#include <cstdio>

using namespace std;
 
int main(){
    double mountain,max = 0.0,min = 100000.0;
  
    while( scanf("%lf" ,&mountain ) != EOF ){
	if( max < mountain ) max = mountain;
	if( min > mountain ) min = mountain;
    }
    cout << max - min << endl;
    return 0;
}
