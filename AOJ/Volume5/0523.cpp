#include <iostream>
#include <set>
#include <cmath>

using namespace std;
 
int main(){
    int n;
 
    while(cin >> n ,n){
	int num;
	set<int> s[2];
 
	for(int i = 0 ; i < n ; i++){
	    cin >> num;
	    s[0].insert(num);
	}
 
	for(int i = 1 ; i <= 2*n ; i++){
	    if(s[0].find(i) == s[0].end()){
		s[1].insert(i);
	    }
	}
 
	bool turn = false;
	int field = 0;
 
	while(true){
	    if(s[0].size() == 0 || s[1].size() == 0){
		break;
	    }
 
	    set<int>::iterator it;
	    for(it = s[turn].begin() ; it != s[turn].end() ; it++){
		if(field < *it){
		    s[turn].erase(it);
		    field = *it;
		    turn = abs(1-turn);
		    break;
		}
	    }     
 
	    if(it == s[turn].end()){
		field = 0;
		turn = abs(1-turn);
	    } 
	}
	cout << s[1].size() << endl;
	cout << s[0].size() << endl;
    }
    return 0;
}
