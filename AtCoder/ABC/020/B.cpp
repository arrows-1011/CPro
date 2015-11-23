#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string a,b;
    cin >> a >> b;
    a += b;
    stringstream ss(a);
    int c; ss >> c;
    cout << c*2 << endl;
    return 0;
}
