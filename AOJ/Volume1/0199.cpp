#include <iostream>
#include <algorithm>
 
using namespace std;

#define MAX 100

int n,m;
char chair[MAX+2];
  
void A(){
    for(int i = 1 ; i <= n ; i++){
	if(chair[i] == '#'){
	    chair[i] = 'A';
	    return;
	}
    }
}
 
void B(){
    int pos = -1;
    for(int i = 1 ; i <= n ; i++){
	if(chair[i] == 'A'){
	    pos = i;
	    break;
	}
    }
   
    if(pos == -1){
	for(int i = n ; i > 0 ; i--){
	    if(chair[i] == '#'){
		chair[i] = 'B';
		return;
	    } 
	}
    }
    else{
	for(int i = n ; i > 0 ; i--){
	    if(chair[i] == '#' && chair[i-1] != 'A' && chair[i+1] != 'A'){
		chair[i] = 'B';
		return;
	    }
	}
  
	for(int i = 1 ; i <= n ; i++){
	    if(chair[i] == '#'){
		chair[i] = 'B';
		return;
	    }
	}
    }
}
  
void C(){
    int cnt = count(chair,chair+n,'#');
  
    if(cnt == n){
	if(n % 2){
	    chair[(n+1)/2] = 'C';
	}
	else{
	    chair[n/2+1] = 'C';
	}
    }
    else{
	for(int i = 1 ; i <= n ; i++){
	    if(chair[i] != '#' && chair[i+1] == '#' && i != n){
		chair[i+1] = 'C';
		return;
	    }
	    if(chair[i] != '#' && chair[i-1] == '#' && i != 1){
		chair[i-1] = 'C';
		return;
	    }
	}
    }
}
  
void D(){
    int Breadth = 0, pos;
    int cnt = count(chair,chair+n,'#');
 
    if(cnt == n){
	chair[1] = 'D';
	return;
    } 
 
    for(int i = 1 ; i <= n ; i++){
	int dist = (1<<29);
	if(chair[i] != '#') continue;
	for(int j = 1 ; j <= n ; j++){
	    if(chair[j] != '#'){
		dist = min(dist,abs(j-i)+1);
	    }
	}
	if(Breadth < dist){
	    Breadth = dist;
	    pos = i;
	} 
    }
  
    chair[pos] = 'D';
}
  
int main(){
    while(cin >> n >> m , n | m){
	char person;
  
	for(int i = 0 ; i <= n+1 ; i++){
	    chair[i] = '#';
	}
  
	for(int i = 0 ; i < m ; i++){
	    cin >> person;
       
	    switch(person){
	    case 'A': 
		A(); 
		break;
	    case 'B': 
		B(); 
		break;
	    case 'C': 
		C(); 
		break;
	    case 'D': 
		D(); 
		break;
	    }
	}
  
	for(int i = 1 ; i <= n ; i++){
	    cout << chair[i];
	}
	cout << endl;
    }
    return 0;
}
