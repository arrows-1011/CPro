#include <iostream>
 
using namespace std;
  
int main(){
    string h;
    int a;
  
    while(cin >> a,a){
	int sum = 1,top = 1,dice[4] = {2,3,4,5};
	for(int i = 0 ; i < a ; i++){
	    cin >> h;
	    int tmp = top;
	    if( i == 0 ) top = 1;
	    if(h == "North"){
		top = dice[0];
		dice[0] = 7 - tmp;
		dice[3] = tmp;
	    }
	    else if(h == "East"){
		top = dice[2];
		dice[2] = 7 - tmp;
		dice[1] = tmp;
	    }
	    else if(h == "West"){
		top = dice[1];
		dice[1] = 7 - tmp;
		dice[2] = tmp; 
	    }
	    else if(h == "South"){
		top = dice[3];
		dice[3] = 7 - tmp;
		dice[0] = tmp;
	    }
	    else if(h == "Right"){
		tmp = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[0];
		dice[0] = dice[1];
		dice[1] = tmp;
	    }
	    else{
		tmp = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[0];
		dice[0] = dice[2];
		dice[2] = tmp; 
	    }
	    sum += top;
	}
	cout << sum << endl;
    }
    return 0;
}
