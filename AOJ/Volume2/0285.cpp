#include <bits/stdc++.h>
 
using namespace std;
 
void solve(int a,int b,int A,int B,string s){
    if(a == A && b == B){
	cout << s << endl;
	return;
    }
    int c = min(a,b), d = max(a,b);
    if(c <= 3 && d >= 5) return;
    if(c == 4 && d == 6) return;
    if(a == 5 && b == 5) return;
    solve(a+1,b,A,B,s+'A');
    solve(a,b+1,A,B,s+'B');
}
 
int main(){
    int A,B;
    cin >> A >> B;
    solve(0,0,A,B,"");
    return 0;
}
