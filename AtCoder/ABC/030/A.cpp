#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    double A,B,C,D;
    cin >> A >> B >> C >> D;
    double E = B/A, F = D/C;
    if(E < F) cout << "AOKI" << endl;
    else if(E > F) cout << "TAKAHASHI" << endl;
    else cout << "DRAW" << endl;
    return 0;
}
