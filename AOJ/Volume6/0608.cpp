#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int A,B,C,D,P;
    cin >> A >> B >> C >> D >> P;
    cout << min(A*P,(C >= P ? B : B + (P-C)*D)) << endl;
    return 0;
}
