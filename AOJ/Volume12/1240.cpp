#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
 
string str;
 
void C(int len){
    char tmp = str[0];
    for(int i = 1 ; i < len; i++){
        str[i-1] = str[i];
    }
    str[len-1] = tmp;
}
 
void J(int len){
    char tmp = str[len-1];
    for(int i = len-2; i >=0 ; i--){
        str[i+1] = str[i];
    }
    str[0] = tmp;
}
 
void E(int len){
    int div = len/2;
     
    if(len%2==0){
        string f = str.substr(0,div) , g = str.substr(div,len-1);
        str = "";
        str += g+f;
    }
    else{
        string f = str.substr(0,div), g = str.substr(div+1,len);
        string mid = str.substr(div,1);
        str = "";
        str += g+mid+f;
    }
}
 
void A(){
    reverse(str.begin(),str.end());
}
 
void M(int len){
    for(int i = 0 ; i < len ; i++){
        if('0' <= str[i] && str[i] <= '8'){
            str[i] += 1;
        }
        else if(str[i] == '9') str[i] = '0';
    }
}
 
void P(int len){
    for(int i = 0 ; i < len ; i++){
        if('1' <= str[i] && str[i] <= '9'){
            str[i] -= 1;
        }
        else if(str[i] == '0') str[i] = '9';
    }
}
 
int main(){
    int n;
    cin >> n;
    while(n--){
        string order;
        cin >> order >> str;
         
        int len = str.size();
        reverse(order.begin(),order.end());
         
        for(int i = 0 ; i < (int)order.size() ; i++){
            switch(order[i]){
	    case 'J':
		J(len);
		break;
                     
	    case 'C':
		C(len);
		break;
                     
	    case 'E':
		E(len);
		break;
                     
	    case 'A':
		A();
		break;
                     
	    case 'M':
		M(len);
		break;
                     
	    case 'P':
		P(len);
		break;
            }
        }
        cout << str << endl;
    }
    return 0;
}
