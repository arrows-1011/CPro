#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int A,B,t[6] = {-10,-5,-1,1,5,10};
    bool used[100] = {false};
    cin >> A >> B;
    queue<int> Q,step;
    Q.push(A); step.push(0);
    used[A] = true;
 
    while(!Q.empty()){
	int s = step.front(); step.pop();
	A = Q.front(); Q.pop();
	if(A == B){ cout << s << endl; break; }
	for(int i = 0 ; i < 6 ; i++){
	    int next = A + t[i];
	    if(next < 100 && !used[next]){
		used[next] = true;
		Q.push(next);
		step.push(s+1);
	    }
	}
    }
    return 0;
}
