#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int v1 = a;
    int v2 = (a == b ? c : b);
    cout << (2*(v1+v2)-a-b-c) << endl;
    return 0;
}
