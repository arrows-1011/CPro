#include <iostream>
 
using namespace std;
 
int main(){
    int Climb_up[150],Climb_down[150];
    int n,t;
    int Box[150];
    int UM,DM;
 
    cin >> t;
    for( int i = 0 ; i < t ; i++ ){
	UM = DM = 0;
 
	cin >> n;
	for( int j = 0 ; j < n ; j++ ){
	    cin >> Box[j];
	    if( j > 0 ){
		if( Box[j-1] < Box[j] ){
		    Climb_up[j] = Box[j] - Box[j-1];
		    Climb_down[j] = 0;
		}
		else if( Box[j-1] > Box[j] ){
		    Climb_down[j] = Box[j-1] - Box[j];
		    Climb_up[j] = 0;
		}
		else if( Box[j-1] == Box[j] ){
		    Climb_up[j] = 0;
		    Climb_down[j] = 0;
		}
	    }
	}
 
	for( int j = 0 ; j < n ; j++ ){
	    if( j > 0 ){
		if( UM < Climb_up[j] ) UM = Climb_up[j];
		if( DM < Climb_down[j] ) DM = Climb_down[j];
	    }
	}
	cout << UM << " " << DM << endl;
    }
    return 0;
}
