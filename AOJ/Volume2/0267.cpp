#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1e4;
 
int n;
vector<int> v,array;
int tri[MAX+1];
 
void init(){
    int t = 1;
    tri[0] = 0;
    for(int i = 1 ; i <= MAX ; i++){
	tri[i] = tri[i-1] + t;
	t++;
    }
}
 
bool check(){
    int len = array.size();
    for(int i = 0 ; i < len ; i++){
	if(array[i] != i+1) return false;
    }
    return true;
}
 
void judge(){
    int LIMIT = MAX,cnt = 0;
    bool possible = false;
 
    while(LIMIT--){
	if(check()){
	    break;
	}
     
	int s = 0, len = array.size();
	for(int i = 0 ; i < len ; i++){
	    if(array[i]){
		array[i]--;
		s++; 
	    }
	}
	array.push_back(s);
	for(int i = 0 ; i < len ; i++){
	    if(!array[i]){
		array.erase(array.begin() + i);
 
	    }
	}
 
	++cnt;
    }
    if(check()) possible = true;
    if(possible) cout << cnt << endl;
    else cout << "-1" << endl;
}
 
int main(){ 
    init(); 
    while(cin >> n ,n){
	int in,sum = 0;
	array.clear();
	for(int i = 0 ; i < n ; i++){
	    cin >> in;
	    sum += in;
	    array.push_back(in);
	}
 
	bool flg = false;
	for(int i = 1 ; i <= MAX ; i++){
	    if(tri[i] == sum){
		flg = true;
		break;
	    } 
	}
 
	if(!flg){
	    cout << "-1" << endl;
	}
	else{
	    judge();
	}
    }
    return 0;
}
