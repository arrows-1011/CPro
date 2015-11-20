#include <iostream>
#include <stack>

using namespace std;
 
int main(){
    string str;
 
    while(getline(cin,str),str != "."){
	stack<char> st;
	int len = str.size();
	bool flg = false;
 
	for(int i = 0 ; i < len ; i++){
	    if(str[i] == '(' || str[i] == '['){
		st.push(str[i]);
		continue;
	    }
	    if(str[i] == ')'){
		if(st.empty()){
		    flg = true;
		    break;
		}
		else if(st.top() == '(') st.pop();
		else{
		    flg = true;
		    break;
		}
	    }
	    else if(str[i] == ']'){
		if(st.empty()){
		    flg = true;
		    break;
		}
		else if(st.top() == '[') st.pop();
		else{
		    flg = true;
		    break;
		}
	    }
	}
	if(!flg&&st.empty()) cout << "yes" << endl;
	else cout << "no" << endl;
    }
    return 0;
}
