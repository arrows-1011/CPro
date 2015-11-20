#include <iostream>
 
using namespace std;
 
int len, l;
string str, in;
 
bool check(int i, int j){
    for(int k = 0 ; k < l ; k++){
	if(i+j*k >= len) return false;
	if(str[k] != in[i+j*k]) return false;
    }
    return true;
}
 
int main(){
    int N, ans = 0;
 
    cin >> N >> str; l = str.size();
    for(int i = 0 ; i < N ; i++){
	cin >> in;
	len = in.size();
	for(int i = 0 ; i < len ; i++){
	    for(int j = 1 ; j < len ; j++){
		if(check(i,j)){
		    ++ans;
		    goto next;
		}
	    }
	}
    next:;
    }
    cout << ans << endl;
    return 0;
}
