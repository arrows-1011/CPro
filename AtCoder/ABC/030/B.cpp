#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n,m;
    cin >> n >> m;
    n %= 12;
    double M = 6*m;
    double N = (n*60+m)*0.5;
    cout << min(360-abs(M-N),abs(M-N)) << endl;
    return 0;
}
