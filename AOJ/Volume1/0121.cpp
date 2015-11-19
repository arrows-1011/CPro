#include <iostream>
#include <queue>
#include <string>
#include <map>
 
using namespace std;
 
bool check(int n){
    return (0 <= n && n < 8);
}
 
void init(map<string,int> &count){
    const int d[4] = {1,-1,4,-4};
    queue<string> Q;
    string t = "01234567";
    Q.push(t);
 
    while(!Q.empty()){
	string now = Q.front(); Q.pop();
	int zero = now.find('0');
	int dist = count[now];    
 
	for(int i = 0 ; i < 4 ; i++){
	    int next = zero + d[i];
   
	    if(!check(next) || (zero == 3 && d[i] == 1)
	       || (zero == 4 && d[i] == -1)) continue;
 
	    swap(now[zero],now[next]);
	    //not visit
	    if(!count[now]){ 
		Q.push(now);
		if(now != t) count[now] = dist + 1;
	    }
	    swap(now[zero],now[next]);
	}
    }
}
 
int main(){
    char in;
    string puzzle;
    map<string,int> count;
 
    init(count);
    while(cin >> in){
	puzzle = in;
	for(int i = 0 ; i < 7 ; i++){
	    cin >> in;
	    puzzle += in;
	}
	cout << count[puzzle] << endl;
    }
    return 0;
}
