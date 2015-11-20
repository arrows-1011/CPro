#include <iostream>

using namespace std;

#define MAX 100
 
int main(){
    int a,b,array[MAX+1];
 
    while(cin >> a >> b){
	fill(array,array+MAX,0);
	array[--a]++;
	array[--b]++;
 
	while(true){
	    cin >> a >> b;
	    if(!a&&!b) break;
	    array[--a]++;
	    array[--b]++;
	}
 
	bool flg = false;
	if((array[0]%2==1)&&(array[1]%2==1)) flg = true;
	for(int i = 2 ; i < MAX ; i++){
	    if(array[i]%2==1) flg = false;
	}
 
	if(!flg) cout << "NG" << endl;
	else cout << "OK" << endl;
    }
    return 0;
}
