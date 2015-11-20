#include <iostream>

using namespace std;
 
long long n;
 
long long inp(){
    cin >> n;
    return n;
}
 
int res(long long n){
    int cnt = 0;
    while(true){
        if(n==1) break;
        cnt++;
        if(n%3==0) n /= 3;
        else n = n/3+1;
    }
    return cnt;
}
 
int main(){
    cout << res(inp()) << endl;
    return 0;
}
