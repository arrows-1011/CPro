#include <bits/stdc++.h>
 
using namespace std;
 
bool isLeap(int Y){
    if(Y % 400 == 0) return true;
    if(Y % 100 == 0) return false;
    if(Y % 4 == 0) return true;
    return false;
}
 
int main(){
    int Y;
    cin >> Y;
    cout << (isLeap(Y) ? "YES" : "NO") << endl;
    return 0;
}
