#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string s,end;
    int N;
    cin >> N >> end;
    int len = end.size();
    bool found = false;
    for(int i = 0 ; ; i++){
	if(len < (int)s.size()){
	    break;
	}
	if(end == s){
	    found = true;
	    cout << i+1 << endl;
	    break;
	}
	if(i != 0){
	    if(i%3 == 1){
		s = 'a' + s + 'c';
	    }else if(i%3 == 2){
		s = 'c' + s + 'a';
	    }else{
		s = 'b' + s + 'b';
	    }
	}else{
	    s = "b";
	}
	if(end == s){
	    found = true;
	    cout << i << endl;
	    break;
	}
    }
    if(!found){
	cout << -1 << endl;
    }
    return 0;
}
